#include "arenderer/ARenderer.h"

#include <print>

// main
//==============================================================================================================================================
int main() {
    arenderer::ARenderer app;

    try {
        app.Run();
    }
    catch (const std::exception& e) {
        std::print(stderr, "{}\n", e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}