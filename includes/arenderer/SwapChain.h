#ifndef ARENDERER_SWAP_CHAIN_H
#define ARENDERER_SWAP_CHAIN_H

#include <vulkan/vulkan.hpp>

#include <GLFW/glfw3.h>

namespace arenderer {
    class PhysicalDevice;
	class SwapChain {
    public:
        VkSwapchainKHR swapChain = VK_NULL_HANDLE;
        std::vector<VkImage> swapChainImages{};
        VkFormat swapChainImageFormat{};
        VkExtent2D swapChainExtent{};
        std::vector<VkImageView> swapChainImageViews{};
        std::vector<VkFramebuffer> swapChainFramebuffers{};

        VkImage depthImage;
        VkDeviceMemory depthImageMemory;
        VkImageView depthImageView;

        VkImage colorImage;
        VkDeviceMemory colorImageMemory;
        VkImageView colorImageView;

        VkFormat depthFormat;

        void Create(VkDevice device, const PhysicalDevice& physicalDevice, VkSurfaceKHR surface, GLFWwindow* windoww);
        void CreateImageViews(VkDevice device);
        void CreateDepthResources(VkDevice device, const PhysicalDevice& physicalDevice);
        void CreateColorResources(VkDevice device, const PhysicalDevice& physicalDevice);
        void CreateFramebuffers(VkDevice device, VkRenderPass renderPass);
        void CreateSyncObjects();
        void Destroy(VkDevice device);

    private:
        VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
        VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities, GLFWwindow* window);
        VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);

	};
}

#endif // !ARENDERER_SWAP_CHAIN_H
