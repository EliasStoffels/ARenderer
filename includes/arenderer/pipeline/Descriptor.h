#ifndef ARENDERER_DESCRIPTOR_H
#define ARENDERER_DESCRIPTOR_H

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <vulkan/vulkan.hpp>

#include <vector>

namespace arenderer {
	struct UniformBufferObject {
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 proj;
	};

	class Descriptor {
		public:
		VkDescriptorSetLayout descriptorSetLayout = VK_NULL_HANDLE;
		VkDescriptorPool descriptorPool = VK_NULL_HANDLE;
		std::vector<VkDescriptorSet> descriptorSets;
		void CreateDescriptorSetLayout(VkDevice device);
		void CreateDescriptorPool(VkDevice device);
		void CreateDescriptorSets(VkDevice device, const std::vector<VkBuffer>& uniformBuffers, const VkImageView& textureImageView, const VkSampler& textureSampler);
		void Destroy(VkDevice device);
	};
}

#endif // !ARENDERER_DESCRIPTOR_H
