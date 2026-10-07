#ifndef ARENDERER_INSTANCE_H
#define ARENDERER_INSTANCE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

namespace arenderer {
	class Instance {
    public:
        // validation layers
        const std::vector<const char*> validationLayers = {
            "VK_LAYER_KHRONOS_validation"
        };

        GLFWwindow* window = VK_NULL_HANDLE;
        VkInstance instance = VK_NULL_HANDLE;
        VkSurfaceKHR surface = VK_NULL_HANDLE;
        VkDebugUtilsMessengerEXT debugMessenger = VK_NULL_HANDLE;
        bool framebufferResized = false;

        void InitWindow();
        void Create();
        void Destroy();
    private:
        bool CheckValidationLayerSupport();
        void CreateInstance();
        void SetupDebugMessenger();
        void CreateSurface();
	};
}

#endif