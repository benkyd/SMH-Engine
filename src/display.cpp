#include "display.h"

Display::Display(std::string name, Logger& logger, int w, int h,
                 SMH_VSYNC_DISPLAY_MODE vsyncMode,
                 SMH_MXAA_MODE mxaaMode)
                    : logger(logger) {

    MXAAMode = mxaaMode;
    VSyncMode = vsyncMode;

    logger << LOGGER_INFO << "Initializing display" << LOGGER_ENDL;
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// MXAA
    if (mxaaMode != MXAA_DEFAULT || mxaaMode != MXAA_DISABLED) {
        int mxaaLevel = 1;
        std::string smxaaLevel = "1";

        switch (mxaaMode) {
            case MXAA_ENABLED:
            case MXAA_2X:
                mxaaLevel = 2;
                smxaaLevel = "2";
                break;
            case MXAA_4X:
                mxaaLevel = 4;
                smxaaLevel = "4";
                break;
            case MXAA_8X:
                mxaaLevel = 8;
                smxaaLevel = "8";
                break;
			case MXAA_16X:
				mxaaLevel = 16;
				smxaaLevel = "16";
				break;
            default:
                mxaaLevel = 2;
                smxaaLevel = "2";
                break;
        }
        
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, mxaaLevel);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, smxaaLevel.c_str());
        logger << LOGGER_INFO << "MXAA set to " << mxaaLevel << "xMSAA" << LOGGER_ENDL;
    } else {
        logger << LOGGER_INFO << "MXAA disabled" << LOGGER_ENDL;
    }

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

    // Create GL window
    logger << LOGGER_INFO << "Creating window" << LOGGER_ENDL;
	window = SDL_CreateWindow(name.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, w, h,
		SDL_WINDOW_OPENGL);
    // Create GL context
    logger << LOGGER_INFO << "Creating OpenGL context" << LOGGER_ENDL;
	glContext = SDL_GL_CreateContext(window);

	SDL_WarpMouseInWindow(window, w / 2, h / 2);
	SDL_SetRelativeMouseMode(SDL_TRUE);

    // Set VSYNC swap interval
    if (vsyncMode == VSYNC_DEFAULT || vsyncMode == VSYNC_ENABLED) {
        SDL_GL_SetSwapInterval(1);
        logger << LOGGER_INFO << "VSync enabled" << LOGGER_ENDL;
    }
    if (vsyncMode == VSYNC_DISABLED) {
        SDL_GL_SetSwapInterval(0);
        logger << LOGGER_INFO << "VSync disabled" << LOGGER_ENDL;
    }

    logger << LOGGER_INFO << "Display set up" << LOGGER_ENDL;

    // Load OpenGL
	gladLoadGLLoader(SDL_GL_GetProcAddress);
	glEnable(GL_MULTISAMPLE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
    logger << LOGGER_INFO << "Loaded OpenGL" << LOGGER_ENDL;
    logger << LOGGER_ENDL;
    isClosed = false;
}





Display::Display(std::string name, Logger& logger, int w, int h,
                 SMH_MXAA_MODE mxaaMode, 
                 SMH_VSYNC_DISPLAY_MODE vsyncMode)
                    : logger(logger) {

    MXAAMode = mxaaMode;
    VSyncMode = vsyncMode;

    logger << LOGGER_INFO << "Initializing display" << LOGGER_ENDL;
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// MXAA
    if (mxaaMode != MXAA_DEFAULT || mxaaMode != MXAA_DISABLED) {
        int mxaaLevel = 1;
        std::string smxaaLevel = "1";

        switch (mxaaMode) {
            case MXAA_ENABLED:
            case MXAA_2X:
                mxaaLevel = 2;
                smxaaLevel = "2";
                break;
            case MXAA_4X:
                mxaaLevel = 4;
                smxaaLevel = "4";
                break;
            case MXAA_8X:
                mxaaLevel = 8;
                smxaaLevel = "8";
                break;
			case MXAA_16X:
				mxaaLevel = 16;
				smxaaLevel = "16";
				break;
            default:
                mxaaLevel = 2;
                smxaaLevel = "2";
                break;
        }
        
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, mxaaLevel);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, smxaaLevel.c_str());
        logger << LOGGER_INFO << "MXAA set to " << mxaaLevel << "xMSAA" << LOGGER_ENDL;
    } else {
        logger << LOGGER_INFO << "MXAA disabled" << LOGGER_ENDL;
    }

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

    // Create GL window
    logger << LOGGER_INFO << "Creating window" << LOGGER_ENDL;
	window = SDL_CreateWindow(name.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, w, h,
		SDL_WINDOW_OPENGL);
    // Create GL context
    logger << LOGGER_INFO << "Creating OpenGL context" << LOGGER_ENDL;
	glContext = SDL_GL_CreateContext(window);

	SDL_WarpMouseInWindow(window, w / 2, h / 2);
	SDL_SetRelativeMouseMode(SDL_TRUE);

    // Set VSYNC swap interval
    if (vsyncMode == VSYNC_DEFAULT || vsyncMode == VSYNC_ENABLED) {
        SDL_GL_SetSwapInterval(1);
        logger << LOGGER_INFO << "VSync enabled" << LOGGER_ENDL;
    }
    if (vsyncMode == VSYNC_DISABLED) {
        SDL_GL_SetSwapInterval(0);
        logger << LOGGER_INFO << "VSync disabled" << LOGGER_ENDL;
    }

    logger << LOGGER_INFO << "Display set up" << LOGGER_ENDL;

    // Load OpenGL
	gladLoadGLLoader(SDL_GL_GetProcAddress);
	glEnable(GL_MULTISAMPLE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
    logger << LOGGER_INFO << "Loaded OpenGL" << LOGGER_ENDL;
    logger << LOGGER_ENDL;
    isClosed = false;
}

void Display::setName(std::string name) {
    SDL_SetWindowTitle(window, name.c_str());
}

void Display::update() {
	SDL_GL_SwapWindow(window);

	glClear(GL_DEPTH_BUFFER_BIT);
	const float clear[] = { 0.1f, 0.45f, 0.9f, 1.0f };
	glClearBufferfv(GL_COLOR, 0, clear);
}

Display::~Display() {
    SDL_DestroyWindow(window);
}
