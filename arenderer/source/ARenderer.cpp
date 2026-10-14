#include "arenderer/ARenderer.h"

#include <print>

constexpr int MAX_FRAMES_IN_FLIGHT = 2;

namespace arenderer {
	ARenderer::ARenderer(const std::string& name, uint32_t width, uint32_t height) {
		m_Window.InitWindow(name, width, height);
		m_Context.Create(m_Window);
		m_SwapChain.Create(width, height, m_Context);
	}

	ARenderer::~ARenderer() {
		m_SwapChain.Destroy(m_Context);
		m_Context.Destroy();
		m_Window.Close();
	}

	void ARenderer::Run() {
		while (!m_Window.ShouldClose()) {
			m_Window.PollEvents();
			DrawFrame();
		}
	}

	void ARenderer::DrawFrame() {
		//std::println("drew frame");
	}
}