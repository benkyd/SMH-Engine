// General includes
#include <chrono>
#include <vector>

// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>

// Custom includes
#define LOGGER_DEFINITION
#include <logger.h>

#include "display.h"
#include "shader.h"
#include "model.h"

int main (int argc, char** argv) {

    std::cout << "-----------------------------\n"
              << "----- SMH Render Engine -----\n"
              << "-------- Version 0.0 --------\n"
              << "----- ©Benjamin Kyd 2019 ----\n"
              << "-----------------------------\n\n";

    Logger logger;

    Display display{"SMH Engine", logger, 1280, 720, MXAA_16X, VSYNC_ENABLED};

	Shader shader;
	shader.load("./resources/shaders/phong").attatch().link().use();

	Mesh mesh{ "./resources/lucy.obj" };
	mesh.setup();

    SDL_Event e;
    while (!display.isClosed) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				display.isClosed = true;
        }

        const Uint8* state = SDL_GetKeyboardState(NULL);

        if (state[SDL_SCANCODE_Q]) {
            mesh.rotation += -1.5f;
        }

        if (state[SDL_SCANCODE_E]) {
            mesh.rotation += 1.5f;
        }

		mesh.bind();
		mesh.render(shader);
		mesh.unbind();

		display.update();
    }

    return 0;
}
