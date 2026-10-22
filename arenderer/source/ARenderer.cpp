#include "arenderer/ARenderer.h"

#include <print>

constexpr int MAX_FRAMES_IN_FLIGHT = 2;

namespace arenderer {
	ARenderer::ARenderer(const std::string& name, uint32_t width, uint32_t height): 
		m_Window(name, width, height), m_Context(m_Window), m_SwapChain(width, height, m_Context), m_Commands(m_Context) {}

	ARenderer::~ARenderer() {
		vkDeviceWaitIdle(m_Context.GetDevice());
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