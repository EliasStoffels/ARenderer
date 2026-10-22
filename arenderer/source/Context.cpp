#include "arenderer/Context.h"
#include "arenderer/Window.h"

#include "VkBootstrap.h"

namespace {
#ifdef NDEBUG
	const bool USE_VALIDATION_LAYERS = false;
#else
	const bool USE_VALIDATION_LAYERS = true;
#endif
}

namespace arenderer {
	Context::Context(const Window& window) {
		vkb::InstanceBuilder builder;

		//make the vulkan instance, with basic debug features
		auto instanceResult = builder.set_app_name("ARendererInstance")
			.request_validation_layers(USE_VALIDATION_LAYERS)
			.use_default_debug_messenger()
			.require_api_version(1, 4, 0)
			.build();

		vkb::Instance vkbInstance = instanceResult.value();

		//grab the instance 
		m_Instance = vkbInstance.instance;

#ifndef NDEBUG
		m_DebugMessenger = vkbInstance.debug_messenger;
#endif // DEBUG

		window.GetVkSurface(m_Instance, m_Surface);

		//vulkan 1.4 features
		VkPhysicalDeviceVulkan14Features features14{ .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES };

		//vulkan 1.3 features
		VkPhysicalDeviceVulkan13Features features13{ .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES };
		features13.dynamicRendering = true;
		features13.synchronization2 = true;

		//vulkan 1.2 features
		VkPhysicalDeviceVulkan12Features features12{ .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES };
		features12.bufferDeviceAddress = true;
		features12.descriptorIndexing = true;


		//use vkbootstrap to select a gpu. 
		//We want a gpu that can write to the GLFW surface and supports vulkan 1.4 with the correct features
		vkb::PhysicalDeviceSelector selector{ vkbInstance };
		vkb::PhysicalDevice physicalDevice = selector
			.set_minimum_version(1, 4)
			.set_required_features_14(features14)
			.set_required_features_13(features13)
			.set_required_features_12(features12)
			.set_surface(m_Surface)
			.prefer_gpu_device_type(vkb::PreferredDeviceType::discrete)
			.select()
			.value();

		//create the final vulkan device
		vkb::DeviceBuilder deviceBuilder{ physicalDevice };

		vkb::Device vkbDevice = deviceBuilder.build().value();

		// Get the VkDevice handle used in the rest of a vulkan application
		m_Device = vkbDevice.device;
		m_PhysicalDevice = physicalDevice.physical_device;

		m_GraphicsQueue = vkbDevice.get_queue(vkb::QueueType::graphics).value();
		m_GraphicsQueueFamilyIdx = vkbDevice.get_queue_index(vkb::QueueType::graphics).value();
	}

	Context::~Context() {
		vkDestroySurfaceKHR(m_Instance, m_Surface, nullptr);
		vkDestroyDevice(m_Device, nullptr);

#ifndef NDEBUG
		vkb::destroy_debug_utils_messenger(m_Instance, m_DebugMessenger);
#endif

		vkDestroyInstance(m_Instance, nullptr);
	}

	VkInstance Context::GetInstance() const noexcept {
		return m_Instance;
	}

	VkSurfaceKHR Context::GetSurface() const noexcept {
		return m_Surface;
	}

	VkDevice Context::GetDevice() const noexcept{
		return m_Device;
	}

	VkPhysicalDevice Context::GetPhysicalDevice() const noexcept{
		return m_PhysicalDevice;
	}

	uint32_t Context::GetQueueFamilyIndex() const noexcept {
		return m_GraphicsQueueFamilyIdx;
	}
}