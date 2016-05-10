#ifndef SDL2_WINDOW_H
#define SDL2_WINDOW_H

#include "window.h"
#include <SDL2/SDL.h>
#include "canvas.h"
#include "renderer3d.h"

namespace ijengine {

    class SDL2Window : public Window {
    public:
        SDL2Window(SDL_Window *window, SDL_Renderer *renderer);
        ~SDL2Window();

        int w() const;
        int h() const;

        Canvas * canvas() const;
        Renderer3d * renderer3d() const;
    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        Canvas *m_canvas;
        Renderer3d *m_renderer3d;
        
        int m_w;
        int m_h;
    };
}

#endif
