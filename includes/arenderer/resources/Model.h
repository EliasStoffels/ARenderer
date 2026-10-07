#ifndef ARENDERER_MODEL_H
#define ARENDERER_MODEL_H

#include "arenderer/Vertex.h"
#include <string>
#include <cstdlib>
#include <vector>

namespace arenderer {
	class Command;
	class Model {
	public:
		std::vector<Vertex> vertices;
		std::vector<uint32_t> indices;
		VkBuffer vertexBuffer = VK_NULL_HANDLE;
		VkDeviceMemory vertexBufferMemory = VK_NULL_HANDLE;
		VkBuffer indexBuffer = VK_NULL_HANDLE;
		VkDeviceMemory indexBufferMemory = VK_NULL_HANDLE;

		void Load(const std::string& modelPath);
		void Destroy(VkDevice device);

		void CreateVertexBuffer(VkDevice device, VkPhysicalDevice physicalDevice, const Command& command, VkQueue graphicsQueue);
		void CreateIndexBuffer(VkDevice device, VkPhysicalDevice physicalDevice, const Command& command, VkQueue graphicsQueue);

	};
}

#endif // ARENDERER_MODEL_H