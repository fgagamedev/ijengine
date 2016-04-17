#ifndef IJENGINE_SDL2CANVAS_H
#define IJENGINE_SDL2CANVAS_H

#include <SDL2/SDL.h>
#include "canvas.h"

namespace ijengine {

    class SDL2Canvas : public Canvas {
    public:
        SDL2Canvas(SDL_Renderer *renderer);
        void draw(const Texture *texture, int x, int y);
        void draw_from_rectangle(const Texture *texture, const SDL_Rect source, const SDL_Rect destiny);

        void set_color(const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpha);
        void update();

        SDL_Renderer * renderer() const;
    private:
        SDL_Renderer *m_renderer;
    };
}

#endif
