#ifndef ARENDERER_A_RENDERER_H
#define ARENDERER_A_RENDERER_H

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "arenderer/Vertex.h"
#include "arenderer/SwapChain.h"
#include "arenderer/Model.h"
#include "arenderer/context/Instance.h"
#include "arenderer/context/Device.h"
#include "arenderer/context/PhysicalDevice.h"
#include "arenderer/pipeline/RenderPass.h"

#include <chrono>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <optional>
#include <algorithm>
#include <fstream>
#include <set>
#include <array>

// structs
//==============================================================================================================================================

struct UniformBufferObject {
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 proj;
};

// global static functions
//==============================================================================================================================================


namespace arenderer {
	class ARenderer {
    public:
        void Run();
    private:
        // members
        Instance instance{};
        PhysicalDevice physicalDevice{};
        Device device{};
        VkQueue graphicsQueue = VK_NULL_HANDLE;
        VkQueue presentQueue = VK_NULL_HANDLE;
        RenderPass renderPass{};
        VkDescriptorSetLayout descriptorSetLayout = VK_NULL_HANDLE;
        VkPipelineLayout pipelineLayout = VK_NULL_HANDLE;
        VkPipeline graphicsPipeline = VK_NULL_HANDLE;
        VkCommandPool commandPool = VK_NULL_HANDLE;
        std::vector<VkCommandBuffer> commandBuffers;
        std::vector<VkSemaphore> imageAvailableSemaphores;
        std::vector<VkSemaphore> renderFinishedSemaphores;
        std::vector<VkFence> inFlightFences;
        uint32_t currentFrame = 0;
        SwapChain swapChain{};

        Model model{};

        std::vector<VkBuffer> uniformBuffers{};
        std::vector<VkDeviceMemory> uniformBuffersMemory{};
        std::vector<void*> uniformBuffersMapped{};

        VkDescriptorPool descriptorPool = VK_NULL_HANDLE;
        std::vector<VkDescriptorSet> descriptorSets;

        std::uint32_t mipLevels;
        VkImage textureImage;
        VkDeviceMemory textureImageMemory;
        VkImageView textureImageView;
        VkSampler textureSampler;

        // required extensions
        std::vector<const char*> GetRequiredExtensions();

        // vulkan init
        //==============================================================================================================================================
        void InitVulkan();
        void LoadModel();
        VkSampleCountFlagBits GetMaxUsableSampleCount();

        // MainLoop
        //==============================================================================================================================================
        void MainLoop();

        // FRAME !!!!!!
        //==============================================================================================================================================
        void DrawFrame();
        void UpdateUniformBuffer(uint32_t currentImage);

        // cleanup
        //==============================================================================================================================================
        void Cleanup();
        void CleanupSwapChain();
        void CreateDescriptorSetLayout();

        // sync objects
        //==============================================================================================================================================
        void CreateSyncObjects();

        // vertex buffer
        //==============================================================================================================================================
        void CreateUniformBuffers();
        void CreateDescriptorPool();
        void CreateDescriptorSets();

        // command buffer
        //==============================================================================================================================================
        void CreateCommandBuffers();
        void RecordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

        // command pool
        //==============================================================================================================================================
        void CreateCommandPool();

        // image
        //==============================================================================================================================================
        void CreateTextureImage();
        void GenerateMipmaps(VkImage image, VkFormat imageFormat, int32_t texWidth, int32_t texHeight, uint32_t mipLevels);
        void TransitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t mipLevels);
        void CopyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
        bool HasStencilComponent(VkFormat format);

        // framebuffers
        //==============================================================================================================================================
        void CreateTextureImageView();
        void CreateTextureSampler();

        // pipelline
        //==============================================================================================================================================
        void CreateGraphicsPipeline();

        //create surface
        //==============================================================================================================================================
        void CreateSurface();

        // instance
        //==============================================================================================================================================
        void CreateInstance();
        // validation layers
        bool CheckValidationLayerSupport();
        // populate the debugMessenger struct
        void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
        // debug setup (obv)
        void SetupDebugMessenger();

        //create swapchain
        //==========================================================================================================================================
        void RecreateSwapChain();

        // shaders
        //==============================================================================================================================================
        static std::vector<char> ReadFile(const std::string& filename);
        VkShaderModule CreateShaderModule(const std::vector<char>& code);
	};

} // namespace arenderer

#endif // ARENDERER_A_RENDERER_H
