#include "arenderer/ARenderer.h"

#include <print>

constexpr int MAX_FRAMES_IN_FLIGHT = 2;

namespace arenderer {
	void ARenderer::Init(const std::string& name, int width, int height) {
		window.InitWindow(name, width, height);
	}

	void ARenderer::Run() {
		while (!window.ShouldClose()) {
			window.PollEvents();
			DrawFrame();
		}
	}

	void ARenderer::DrawFrame() {
		std::println("drew frame");
	}
}