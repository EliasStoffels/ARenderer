#include "arenderer/ARenderer.h"

// main
//==============================================================================================================================================
int main() {
    arenderer::ARenderer app;

    try {
        app.Run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}