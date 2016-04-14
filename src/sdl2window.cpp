#include "sdl2window.h"
#include "sdl2canvas.h"
#include <SDL2/SDL.h>

namespace ijengine {

    SDL2Window::SDL2Window(SDL_Window *new_window, SDL_Renderer *actual_renderer) :
        m_window(new_window), m_renderer(actual_renderer), m_canvas(new SDL2Canvas(actual_renderer)), m_w(0), m_h(0)
    {
        if (m_window)
        {
            SDL_GetWindowSize(m_window, &m_w, &m_h);
        }
    }

    SDL2Window::~SDL2Window()
    {
        if (m_renderer) {
            SDL_DestroyRenderer(m_renderer);
        }

        if (m_window) {
            SDL_DestroyWindow(m_window);
        }
    }

    int
    SDL2Window::w() const
    {
        return m_w;
    }

    int
    SDL2Window::h() const
    {
        return m_h;
    }

    Canvas *
    SDL2Window::canvas() const
    {
        return m_canvas;
    }
}
