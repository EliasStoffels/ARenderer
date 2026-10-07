#ifndef ARENDERER_COMMAND_H
#define ARENDERER_COMMAND_H

#include <vulkan/vulkan.hpp>

namespace arenderer {
    class PhysicalDevice;
    class Command {
    public:
        VkCommandPool commandPool = VK_NULL_HANDLE;
        std::vector<VkCommandBuffer> commandBuffers;

        void CreateCommandPool(VkDevice device, const PhysicalDevice& physicalDevice);
        void CreateCommandBuffers(VkDevice device, int maxFramesInFlight);
        void RecordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
        VkCommandBuffer BeginSingleTimeCommands(VkDevice device) const;
        void EndSingleTimeCommands(VkDevice device, VkQueue graphicsQueue, VkCommandBuffer commandBuffer) const;

        void Destroy(VkDevice device);
    };
}

#endif // ! ARENDERER_COMMAND_H
