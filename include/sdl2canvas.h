#ifndef IJENGINE_SDL2CANVAS_H
#define IJENGINE_SDL2CANVAS_H

#include <SDL2/SDL.h>
#include "canvas.h"

namespace ijengine {

    class SDL2Canvas : public Canvas {
    public:
        SDL2Canvas(SDL_Renderer *renderer);
        void draw(const Texture *texture, int x, int y);

        SDL_Renderer * renderer() const { return m_renderer; }
        void update();
    private:
        SDL_Renderer *m_renderer;
    };
}

#endif
