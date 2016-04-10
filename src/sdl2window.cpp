#include "sdl2window.h"
#include <SDL2/SDL.h>

namespace ijengine {

    SDL2Window::SDL2Window(SDL_Window *new_window, SDL_Renderer *actual_renderer) :
        sdl_window(new_window),
        renderer(actual_renderer)
    {
    }

    SDL2Window::~SDL2Window()
    {
        if (renderer != nullptr) {
            SDL_DestroyRenderer(renderer);
        }

        if (sdl_window != nullptr) {
            SDL_DestroyWindow(sdl_window);
        }
    }

    int
    SDL2Window::w() const
    {
        return 0;
    }

    int
    SDL2Window::h() const
    {
        return 0;
    }

}
