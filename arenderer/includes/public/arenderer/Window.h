#ifndef ARENDERER_WINDOW_H
#define ARENDERER_WINDOW_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>

namespace arenderer {
	class Window {
		GLFWwindow* window = nullptr;
	public:
		Window(const std::string& name, int width, int height);
		~Window();

		Window(const Window& other) = delete;
		Window(Window&& other) = delete;
		Window& operator= (const Window& other) = delete;
		Window& operator= (Window&& other) = delete;

		bool framebufferResized = false;
		bool ShouldClose() const noexcept;
		void PollEvents();
		glm::ivec2 GetSize() const;
		void GetVkSurface(VkInstance instance, VkSurfaceKHR& surface) const;
	};
}

#endif // !ARENDERER_WINDOW_H