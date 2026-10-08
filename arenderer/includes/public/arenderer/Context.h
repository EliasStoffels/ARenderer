#ifndef ARENDERER_CONTEXT_H
#define ARENDERER_CONTEXT_H

#include <vulkan/vulkan.h>

#include <string>

namespace arenderer {
	class Window;
	class Context final{
	public:
		void Init(const Window& window);
	private:
		VkInstance instance = VK_NULL_HANDLE;
		VkSurfaceKHR surface = VK_NULL_HANDLE;
		VkDevice device = VK_NULL_HANDLE;
		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	};
}

#endif // !ARENDERER_CONTEXT_H
