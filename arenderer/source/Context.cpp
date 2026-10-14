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
	void Context::Init(const Window& window) {
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

		//vulkan 1.3 features
		VkPhysicalDeviceVulkan14Features features14{ .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES };

		VkPhysicalDeviceVulkan13Features features13{ .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES };
		features13.dynamicRendering = true;
		features13.synchronization2 = true;

		//vulkan 1.2 features
		VkPhysicalDeviceVulkan12Features features12{ .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES };
		features12.bufferDeviceAddress = true;
		features12.descriptorIndexing = true;


		//use vkbootstrap to select a gpu. 
		//We want a gpu that can write to the SDL surface and supports vulkan 1.3 with the correct features
		vkb::PhysicalDeviceSelector selector{ vkbInstance };
		vkb::PhysicalDevice physicalDevice = selector
			.set_minimum_version(1, 3)
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

	}
}