#include "color.h"
#include "sdl2canvas.h"
#include "sdl2texture.h"
#include <SDL2/SDL_image.h>

using namespace ijengine;

SDL2Canvas::SDL2Canvas(SDL_Renderer *r, int width, int height)
    : m_renderer(r), m_w(width), m_h(height), m_draw_color(Color::WHITE),
    m_clear_color(Color::BLACK)
{
    SDL_SetRenderDrawColor(m_renderer, m_draw_color.r(), m_draw_color.g(),
        m_draw_color.b(), m_draw_color.a());
}

void
SDL2Canvas::draw(const Texture *texture, int x, int y)
{
    const SDL2Texture *text = dynamic_cast<const SDL2Texture *>(texture);
    SDL_Rect dest {x, y, texture->w(), texture->h() };
    SDL_RenderCopy(m_renderer, text->texture(), nullptr, &dest);
}

void
SDL2Canvas::draw(const Texture *texture, const Rectangle& section, int x, int y)
{
    const SDL2Texture *text = dynamic_cast<const SDL2Texture *>(texture);
    SDL_Rect src { section.x(), section.y(), section.w(), section.h() };
    SDL_Rect dest {x, y, section.w(), section.h() };

    SDL_RenderCopy(m_renderer, text->texture(), &src, &dest);
}

void
SDL2Canvas::clear()
{
    SDL_SetRenderDrawColor(m_renderer, m_clear_color.r(), m_clear_color.g(),
        m_clear_color.b(), m_clear_color.a());

    SDL_RenderClear(m_renderer);

    SDL_SetRenderDrawColor(m_renderer, m_draw_color.r(), m_draw_color.g(),
        m_draw_color.b(), m_draw_color.a());
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
SDL2Canvas::draw(const Rectangle& rectangle)
{
    // Rectangle's (x, y) represents the center of the rectangle.
    // Thus, we find the leftmost (and uppermost) point to be used as "origin"
    // in order to adapt it to SDL requirements.
    int leftmost_x = rectangle.x() - rectangle.w() / 2;
    int uppermost_y = rectangle.y() - rectangle.h() / 2;

    SDL_Rect rect { leftmost_x, uppermost_y, rectangle.w(), rectangle.h() };
    SDL_RenderFillRect(m_renderer, &rect);
}

void
SDL2Canvas::draw(const Point& point)
{
    SDL_RenderDrawPoint(m_renderer, point.x(), point.y());
}

void
SDL2Canvas::draw(const Line& line)
{
    SDL_RenderDrawLine(m_renderer, line.x1(), line.y1(), line.x2(), line.y2());
}
