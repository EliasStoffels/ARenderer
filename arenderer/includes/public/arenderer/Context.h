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
		VkInstance m_Instance = VK_NULL_HANDLE;
		VkSurfaceKHR m_Surface = VK_NULL_HANDLE;
		VkDevice m_Device = VK_NULL_HANDLE;
		VkPhysicalDevice m_PhysicalDevice = VK_NULL_HANDLE;
#ifndef NDEBUG
		VkDebugUtilsMessengerEXT m_DebugMessenger = VK_NULL_HANDLE;
#endif // DEBUG

	};
}

#endif // !ARENDERER_CONTEXT_H
