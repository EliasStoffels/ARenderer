#ifndef ARENDERER_ARENDERER_H
#define ARENDERER_ARENDERER_H

#include <cstdint>

#include "arenderer/Window.h"
#include "arenderer/Context.h"
#include "arenderer/SwapChain.h"
#include "arenderer/Commands.h"

namespace arenderer {
	class ARenderer final{
	public:
		ARenderer(const std::string& name, uint32_t width, uint32_t heigh);
		~ARenderer();

		ARenderer(const ARenderer& other) = delete;
		ARenderer(ARenderer&& other) = delete;
		ARenderer& operator= (const ARenderer& other) = delete;
		ARenderer& operator= (ARenderer&& other) = delete;

		void Run();

	private:
		void DrawFrame();
		Window m_Window;
		Context m_Context;
		SwapChain m_SwapChain;
		Commands m_Commands;
	};
}

#endif // !ARENDERER_ARENDERER_H