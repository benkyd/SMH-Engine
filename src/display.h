#ifndef SMHENGINE_SRC_DISPLAY_H_
#define SMHENGINE_SRC_DISPLAY_H_

#include <string>

#include <glad/glad.hpp>

// SDL includes different on windows
// the way i have it set up so i gotta
// do it like this unfortunately 
#if _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <logger.h>

typedef enum {
    VSYNC_DEFAULT,
    VSYNC_DISABLED,
    VSYNC_ENABLED,
} SMH_VSYNC_DISPLAY_MODE;

typedef enum {
    MXAA_DEFAULT,
    MXAA_DISABLED,
    MXAA_ENABLED,
    MXAA_2X,
    MXAA_4X,
    MXAA_8X
} SMH_MXAA_MODE;

class Display {
public:
    Display(std::string name, Logger& logger, int w, int h,
            SMH_VSYNC_DISPLAY_MODE vsyncMode = VSYNC_DEFAULT, 
            SMH_MXAA_MODE mxaaMode = MXAA_DEFAULT);

    Display(std::string name, Logger& logger, int w, int h,
            SMH_MXAA_MODE mxaaMode = MXAA_DEFAULT, 
            SMH_VSYNC_DISPLAY_MODE vsyncMode = VSYNC_DEFAULT);

    void setName(std::string name);

    bool isClosed = true;

    SDL_Window* window;
    SDL_GLContext glContext;

    SMH_VSYNC_DISPLAY_MODE VSyncMode = VSYNC_DEFAULT;
    SMH_MXAA_MODE MXAAMode = MXAA_DEFAULT;

    virtual ~Display();
private:
    Logger& logger;
};

#endif
