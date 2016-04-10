#include "sdl2Dvideo.h"
#include "sdl2window.h"

#include <SDL2/SDL.h>

namespace ijengine {

    SDL2DVideo::SDL2DVideo()
    {
        if (SDL_WasInit(SDL_INIT_VIDEO) == 0 and SDL_InitSubSystem(SDL_INIT_VIDEO))
            throw "Error on SDL2DVideo::SDL2DVideo()";
    }

    SDL2DVideo::~SDL2DVideo()
    {
        if (SDL_WasInit(SDL_INIT_VIDEO))
            SDL_QuitSubSystem(SDL_INIT_VIDEO);
    }

    Window *
    SDL2DVideo::create_window(int w, int h)
    {
        SDL_Window *window;
        SDL_Renderer *renderer;

        if (SDL_CreateWindowAndRenderer(w, h, 0, &window, &renderer))
            return nullptr;

        return new SDL2Window(window, renderer);
    }

}
