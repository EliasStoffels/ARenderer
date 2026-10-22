#ifndef ARENDERER_CONTEXT_H
#define ARENDERER_CONTEXT_H

#include <vulkan/vulkan.h>
#include <string>
#include <memory>

namespace arenderer {
	class Window;
	class Context final{
	public:
		Context(const Window& window);
		~Context();

		Context(const Context& other) = delete;
		Context(Context&& other) = delete;
		Context& operator= (const Context& other) = delete;
		Context& operator= (Context&& other) = delete;

		VkInstance GetInstance() const noexcept;
		VkSurfaceKHR GetSurface() const noexcept;
		VkDevice GetDevice() const noexcept;
		VkPhysicalDevice GetPhysicalDevice() const noexcept;
		uint32_t GetQueueFamilyIndex() const noexcept;
	private:
		VkInstance m_Instance = VK_NULL_HANDLE;
		VkSurfaceKHR m_Surface = VK_NULL_HANDLE;
		VkDevice m_Device = VK_NULL_HANDLE;
		VkPhysicalDevice m_PhysicalDevice = VK_NULL_HANDLE;
		VkQueue m_GraphicsQueue = VK_NULL_HANDLE;
		uint32_t m_GraphicsQueueFamilyIdx;

#ifndef NDEBUG
		VkDebugUtilsMessengerEXT m_DebugMessenger = VK_NULL_HANDLE;
#endif // DEBUG
	};
}

#endif // !ARENDERER_CONTEXT_H
