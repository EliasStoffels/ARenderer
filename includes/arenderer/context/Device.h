#ifndef ARENDERER_DEVICE_H
#define ARENDERER_DEVICE_H

#include <vulkan/vulkan.hpp>

namespace arenderer {
	class Instance;
	class PhysicalDevice;
	class Device {
	public:
		VkDevice device = VK_NULL_HANDLE;
		void Create(const Instance& instance,const PhysicalDevice& physicalDevice);
	};

}

#endif // ARENDERER_DEVICE_H