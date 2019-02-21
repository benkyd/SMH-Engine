// General includes
#include <chrono>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Custom includes
#define LOGGER_DEFINITION
#include <logger.h>

#include "display.h"

int main (int argc, char** argv) {
    Logger logger;
    Display display {"SMH Engine", 1280, 720, logger, MXAA_8X, VSYNC_ENABLED};

    

    return 0;
}
