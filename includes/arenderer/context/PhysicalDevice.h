#ifndef ARENDERER_PHYSICAL_DEVICE_H
#define ARENDERER_PHYSICAL_DEVICE_H

#include <vulkan/vulkan.hpp>

namespace arenderer {
	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool IsComplete() {
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};

	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities{};
		std::vector<VkSurfaceFormatKHR> formats{};
		std::vector<VkPresentModeKHR> presentModes{};
	};

	class Instance;
	class PhysicalDevice {
	public:
		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
		VkSampleCountFlagBits msaaSamples = VK_SAMPLE_COUNT_1_BIT;
		const std::vector<const char*> deviceExtensions = {
			VK_KHR_SWAPCHAIN_EXTENSION_NAME
		};
		QueueFamilyIndices queueFamilyIndices{};
		SwapChainSupportDetails swapChainSupportDetails{};
		void Pick(const Instance& instance);
	private:
		bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
		bool IsDeviceSuitable(VkPhysicalDevice device, VkSurfaceKHR surface);
	};

}

#endif // ARENDERER_PHYSICAL_DEVICE_H