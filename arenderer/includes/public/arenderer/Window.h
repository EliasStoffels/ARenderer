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
		bool framebufferResized = false;
		void InitWindow(const std::string& name, int width, int height);
		bool ShouldClose() const noexcept;
		void PollEvents();
		void Close() const;
		glm::ivec2 GetSize() const;
		void GetVkSurface(VkInstance instance, VkSurfaceKHR& surface) const;
	};
}

#endif // !ARENDERER_WINDOW_H