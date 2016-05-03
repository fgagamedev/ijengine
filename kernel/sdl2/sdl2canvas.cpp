#include "sdl2canvas.h"
#include "sdl2texture.h"
#include <iostream>

#include <SDL2/SDL_image.h>

using std::cout;
using std::endl;

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
SDL2Canvas::drawRect(Rectangle rectangle, int r, int g, int b)
{
    // Rectangle's (x, y) represents the center of the rectangle.
    // Thus, we find the leftmost (and uppermost) point to be used as "origin" in order to adapt it to SDL requirements.
    int leftmost_x = rectangle.x() - rectangle.w() / 2;
    int uppermost_y = rectangle.y() - rectangle.h() / 2;

    SDL_Rect rect {leftmost_x, uppermost_y, rectangle.w(), rectangle.h()};
    SDL_SetRenderDrawColor(m_renderer, r, g, b, 255);
    SDL_RenderFillRect(m_renderer, &rect);
}

void
SDL2Canvas::drawPoint(Point point, int r, int g, int b)
{
    SDL_SetRenderDrawColor(m_renderer, r, g, b, 255);
    SDL_RenderDrawPoint(m_renderer, point.x(), point.y());
}

void
SDL2Canvas::drawLine(Line line, int r, int g, int b)
{
    SDL_SetRenderDrawColor(m_renderer, r, g, b, 255);
    SDL_RenderDrawLine(m_renderer, line.x1(), line.y1(), line.x2(), line.y2());
}