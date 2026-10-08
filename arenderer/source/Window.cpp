#include "arenderer/Window.h"

#include <stdexcept>

namespace {
	static void FramebufferResizeCallback(GLFWwindow* window, int width, int height) {
		auto app = reinterpret_cast<arenderer::Window*>(glfwGetWindowUserPointer(window));
		app->framebufferResized = true;
	}
}

namespace arenderer {
	void Window::InitWindow(const std::string& name, int width, int height) {
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
		glfwSetWindowUserPointer(window, this);
		glfwSetFramebufferSizeCallback(window, FramebufferResizeCallback);
	}

	bool Window::ShouldClose() const noexcept {
		return glfwWindowShouldClose(window);
	}

	void Window::PollEvents() {
		glfwPollEvents();
	}

	void Window::Close() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	glm::ivec2 Window::GetSize() {
		int width;
		int height;
		glfwGetWindowSize(window, &width, &height);
		return { width, height };
	}

	VkSurfaceKHR Window::GetVkSurface(VkInstance instance, VkSurfaceKHR& surface) {
		if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS) {
			throw std::runtime_error("failed to create window surface!");
		}
	}
}