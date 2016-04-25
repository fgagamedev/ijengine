#include "sdl2canvas.h"
#include "sdl2texture.h"
#include <iostream>

#include <SDL2/SDL_image.h>


SDL2Canvas::SDL2Canvas(SDL_Renderer *r)
    : m_renderer(r)
{
}

void
SDL2Canvas::draw(const Texture *texture, int x, int y)
{
}
/*    const SDL2Texture *text = dynamic_cast<const SDL2Texture *>(texture);

    SDL_Rect source {x, y, texture->w(), texture->h() };

    SDL_RenderCopy(m_renderer, text->texture(), nullptr, &source);
    SDL_RenderPresent(m_renderer);
}

void
SDL2Canvas::draw_from_rectangle(const Texture *texture, SDL_Rect source, SDL_Rect destiny)
{
    const SDL2Texture *text = dynamic_cast<const SDL2Texture *>(texture);

    SDL_RenderCopy(m_renderer, text->texture(), &source, &destiny);
    SDL_RenderPresent(m_renderer);
}
*/

void
SDL2Canvas::clear()
{
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderClear(m_renderer);
}

void
SDL2Canvas::set_color(unsigned char r, unsigned char g, unsigned char b,
    unsigned char a)
{
    SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}

SDL_Renderer *
SDL2Canvas::renderer() const
{
    return m_renderer;
}

void
SDL2Canvas::update()
{
    SDL_RenderPresent(m_renderer);
}

void
SDL2Canvas::drawRect(int x, int y, int w, int h, int r, int g, int b)
{
    SDL_Rect rect { x, y, w, h };
    SDL_SetRenderDrawColor(m_renderer, r, g, b, 255);
    SDL_RenderFillRect(m_renderer, &rect);
}
