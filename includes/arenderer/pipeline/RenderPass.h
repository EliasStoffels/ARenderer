#ifndef ARENDERER_RENDERPASS_H
#define ARENDERER_RENDERPASS_H

#include <vulkan/vulkan.hpp>

namespace arenderer {
	class PhysicalDevice;
	class SwapChain;
	class RenderPass {
	public:
		VkRenderPass renderPass = VK_NULL_HANDLE;
		void Create(VkDevice device, const PhysicalDevice& physicalDevice, const SwapChain& swapChain);
		void Destroy(VkDevice device);
	};
}

#endif // !ARENDERER_RENDERPASS_H
