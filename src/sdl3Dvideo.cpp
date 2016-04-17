#include "sdl3Dvideo.h"
#include "sdl2window.h"

#include <SDL2/SDL.h>

namespace ijengine {

    SDL3DVideo::SDL3DVideo()
    {
        if (SDL_WasInit(SDL_INIT_VIDEO) == 0 and SDL_InitSubSystem(SDL_INIT_VIDEO))
            throw "Error on SDL2DVideo::SDL2DVideo()";
    }

    SDL3DVideo::~SDL3DVideo()
    {
        if (SDL_WasInit(SDL_INIT_VIDEO))
            SDL_QuitSubSystem(SDL_INIT_VIDEO);
    }

    Window *
    SDL3DVideo::create_window(int w, int h)
    {
        SDL_Window *window;
        SDL_Renderer *renderer;

        if (SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_OPENGL, &window, &renderer))
            return nullptr;
        SDL_GL_CreateContext(window);
        return new SDL2Window(window, renderer);
    }

}
