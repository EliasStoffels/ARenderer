#include "arenderer/ARenderer.h"

#include <print>

constexpr int WIDHT = 1400;
constexpr int HEIGHT = 800;
const std::string WINDOW_NAME = "ARenderer";

// main
//==============================================================================================================================================
int main() {
    arenderer::ARenderer app{};
    try {
        app.Init(WINDOW_NAME, WIDHT, HEIGHT);
        app.Run();
    }
    catch (const std::exception& e) {
        std::println(stderr, "{}", e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}