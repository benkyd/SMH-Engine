#ifndef SRC_TIMERS_H_
#define SRC_TIMERS_H_

// General includes
#include <chrono>

// GL includes
#if _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

// Custom includes
#include <logger.h>

std::chrono::high_resolution_clock timer;
auto FPSCalculateLast = timer.now();
auto FPSClock = SDL_GetTicks();

auto UpdateClock = SDL_GetTicks();

void FPSCount(Logger& logger) {
    if (SDL_GetTicks() - FPSClock >= 1000) {
        auto deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(timer.now() - FPSCalculateLast).count();
        logger << LOGGER_INFO << "FPS: " << (int)(1 / ((float)deltaTime * 1e-9)) << LOGGER_ENDL;
        FPSClock = SDL_GetTicks();
    }
    FPSCalculateLast = timer.now();
}

bool UPSTimer() {
    return (SDL_GetTicks() - UpdateClock >= 10);
}

#endif
