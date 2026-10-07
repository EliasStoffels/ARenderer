#ifndef ARENDERER_GRAPHICS_PIPELINE
#define ARENDERER_GRAPHICS_PIPELINE

#include <vulkan/vulkan.hpp>

namespace arenderer {
	class GraphicsPipeline {
	public:
		VkPipelineLayout pipelineLayout = VK_NULL_HANDLE;
		VkPipeline graphicsPipeline = VK_NULL_HANDLE;
		void Create();
	};
}

#endif // !ARENDERER_GRAPHICS_PIPELINE
