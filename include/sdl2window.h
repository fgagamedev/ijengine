#ifndef SDL2_WINDOW_H
#define SDL2_WINDOW_H

#include "window.h"
#include <SDL2/SDL.h>

namespace ijengine {

    class SDL2Window : public Window {
    public:
        SDL2Window(SDL_Window *window, SDL_Renderer *renderer);
        ~SDL2Window();
        int w() const;
        int h() const;

    private:
        SDL_Window *sdl_window;
        SDL_Renderer *renderer;
    };
}

#endif
