#ifndef ARENDERER_ARENDERER_H
#define ARENDERER_ARENDERER_H

#include <cstdint>

#include "arenderer/Window.h"
#include "arenderer/Context.h"
#include "arenderer/SwapChain.h"

namespace arenderer {
	class ARenderer final{
	public:
		ARenderer(const std::string& name, uint32_t width, uint32_t heigh);
		~ARenderer();
		void Run();

	private:
		void DrawFrame();
		Window m_Window{};
		Context m_Context{};
		SwapChain m_SwapChain{};
	};
}

#endif // !ARENDERER_ARENDERER_H