#ifndef ARENDERER_TEXTURE_H
#define ARENDERER_TEXTURE_H

#include <vulkan/vulkan.hpp>
#include <cstdint>

namespace arenderer {
    class Device;
    class PhysicalDevice;
    class Command;
	class Texture {
    public:
        std::uint32_t mipLevels;
        VkImage textureImage;
        VkDeviceMemory textureImageMemory;
        VkImageView textureImageView;
        void CreateTextureImage(const Device& device, const PhysicalDevice& physicalDevice, const Command& command, const std::string& path);
        void CreateTextureImageView(VkDevice device);
        void Destroy(VkDevice device);

    private:
        void GenerateMipmaps(const Device& device, VkPhysicalDevice physicalDevice, const Command& command, VkImage image, VkFormat imageFormat, int32_t texWidth, int32_t texHeight, uint32_t mipLevels);
        void TransitionImageLayout(const Device& device, const Command& command, VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t mipLevels);
        void CopyBufferToImage(const Device& device, const Command& command, VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
        bool HasStencilComponent(VkFormat format);
	};
}

#endif // !ARENDERER_TEXTURE_H
