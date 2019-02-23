// General includes
#include <chrono>
#include <vector>

// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>

// Custom includes
#define OBJL_DEFINITION
#define LOGGER_DEFINITION
#include <logger.h>

#include "display.h"
#include "model.h"

int main (int argc, char** argv) {

    std::cout << "-----------------------------\n"
              << "----- SMH Render Engine -----\n"
              << "-------- Version 0.0 --------\n"
              << "----- ©Benjamin Kyd 2019 ----\n"
              << "-----------------------------\n\n";

    Logger logger;

    Display display {"SMH Engine", logger, 1280, 720, MXAA_4X, VSYNC_ENABLED};

    SDL_Event e;
    while (!display.isClosed) {
        while (SDL_PollEvent(&e))
            if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				display.isClosed = true;


        SDL_GL_SwapWindow(display.window);
    }

    return 0;
}
