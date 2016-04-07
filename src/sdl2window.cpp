#include "sdl2window.h"

namespace ijengine {

    SDL2Window::SDL2Window(SDL_Window *, SDL_Renderer *)
    {
    }

    SDL2Window::~SDL2Window()
    {
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
