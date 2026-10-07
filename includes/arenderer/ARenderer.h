#ifndef ARENDERER_A_RENDERER_H
#define ARENDERER_A_RENDERER_H

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "arenderer/Vertex.h"
#include "arenderer/SwapChain.h"
#include "arenderer/resources/Model.h"
#include "arenderer/resources/Texture.h"
#include "arenderer/context/Instance.h"
#include "arenderer/context/Device.h"
#include "arenderer/context/PhysicalDevice.h"
#include "arenderer/pipeline/RenderPass.h"
#include "arenderer/pipeline/Descriptor.h"
#include "arenderer/sync/Command.h"

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

namespace arenderer {
	class ARenderer {
    public:
        void Run();
    private:
        // members
        Instance instance{};
        PhysicalDevice physicalDevice{};
        Device device{};
        RenderPass renderPass{};
        Descriptor descriptor{};
        VkPipelineLayout pipelineLayout = VK_NULL_HANDLE;
        VkPipeline graphicsPipeline = VK_NULL_HANDLE;
        Command command{};
        std::vector<VkSemaphore> imageAvailableSemaphores;
        std::vector<VkSemaphore> renderFinishedSemaphores;
        std::vector<VkFence> inFlightFences;
        uint32_t currentFrame = 0;
        SwapChain swapChain{};

        Model model{};

        std::vector<VkBuffer> uniformBuffers{};
        std::vector<VkDeviceMemory> uniformBuffersMemory{};
        std::vector<void*> uniformBuffersMapped{};

        Texture texture{};
        VkSampler textureSampler = VK_NULL_HANDLE;

        void InitVulkan();
        void MainLoop();
        void DrawFrame();
        void Cleanup();


        void UpdateUniformBuffer(uint32_t currentImage);
        void CleanupSwapChain();
        void CreateSyncObjects();
        void CreateUniformBuffers();
        void RecordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
        void CreateTextureSampler();
        void CreateGraphicsPipeline();
        void RecreateSwapChain();
	};

} // namespace arenderer

#endif // ARENDERER_A_RENDERER_H
