#ifndef ARENDERER_SAMPLER_H
#define ARENDERER_SAMPLER_H

#include <vulkan/vulkan.hpp>

namespace arenderer {
	class Sampler {
	public:
		VkSampler textureSampler = VK_NULL_HANDLE;
		void Create(VkDevice device, VkPhysicalDevice physicalDevice);
		void Destroy(VkDevice device);
	};
}

#endif // !ARENDERER_SAMPLER_H
