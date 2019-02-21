#include "display.h"

Display::Display(std::string name, int w, int h, Logger& logger, 
                 SMH_VSYNC_DISPLAY_MODE vsyncMode,
                 SMH_MXAA_MODE mxaaMode) {

    MXAAMode = mxaaMode;
    VSyncMode = vsyncMode;

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
            default:
                mxaaLevel = 2;
                smxaaLevel = "2";
                break;
        }
        
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, mxaaLevel);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, smxaaLevel.c_str());
    }

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

    // Create GL window
	window = SDL_CreateWindow(name.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, w, h,
		SDL_WINDOW_OPENGL);
    // Create GL context
	glContext = SDL_GL_CreateContext(window);

    // Set VSYNC swap interval
    if (vsyncMode == VSYNC_DEFAULT || vsyncMode == VSYNC_ENABLED)
        SDL_GL_SetSwapInterval(1);
    if (vsyncMode == VSYNC_DISABLED)
        SDL_GL_SetSwapInterval(0);

    // Load OpenGL
	gladLoadGLLoader(SDL_GL_GetProcAddress);
}

Display::Display(std::string name, int w, int h, Logger& logger, 
                 SMH_MXAA_MODE mxaaMode, 
                 SMH_VSYNC_DISPLAY_MODE vsyncMode) {

    MXAAMode = mxaaMode;
    VSyncMode = vsyncMode;

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
            default:
                mxaaLevel = 2;
                smxaaLevel = "2";
                break;
        }
        
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
        SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, mxaaLevel);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, smxaaLevel.c_str());
    }

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

    // Create GL window
	window = SDL_CreateWindow(name.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, w, h,
		SDL_WINDOW_OPENGL);
    // Create GL context
	glContext = SDL_GL_CreateContext(window);

    // Set VSYNC swap interval
    if (vsyncMode == VSYNC_DEFAULT || vsyncMode == VSYNC_ENABLED)
        SDL_GL_SetSwapInterval(1);
    if (vsyncMode == VSYNC_DISABLED)
        SDL_GL_SetSwapInterval(0);

    // Load OpenGL
	gladLoadGLLoader(SDL_GL_GetProcAddress);
}

void Display::setName(std::string name) {
    SDL_SetWindowTitle(window, name.c_str());
}

Display::~Display() {
    SDL_DestroyWindow(window);
}
