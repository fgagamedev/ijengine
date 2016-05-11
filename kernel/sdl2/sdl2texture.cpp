#include "sdl2texture.h"
#include "sdl2canvas.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace ijengine {

    SDL2Texture::SDL2Texture(SDL_Texture *t, int width, int height)
        : m_texture(t), m_w(width), m_h(height)
    {
    }

    SDL2Texture *
    SDL2Texture::load_texture_from_path(const string& path, const Canvas *c)
    {
        SDL_Surface *surface_from_img = IMG_Load(path.c_str());

        if (not surface_from_img)
            return nullptr;

        const SDL2Canvas *canvas = dynamic_cast<const SDL2Canvas *>(c);
        SDL_Renderer *r = canvas->renderer();

        SDL_Texture *texture_from_surface = SDL_CreateTextureFromSurface(r, surface_from_img);
        if (not texture_from_surface)
        {
            SDL_FreeSurface(surface_from_img);
            return nullptr;
        }

        int w = surface_from_img->w;
        int h = surface_from_img->h;

        SDL_FreeSurface(surface_from_img);

        return new SDL2Texture(texture_from_surface, w, h);
    }

    SDL2Texture::~SDL2Texture()
    {
        if (m_texture)
            SDL_DestroyTexture(m_texture);
    }

    SDL_Texture *
    SDL2Texture::texture() const
    {
        return m_texture;
    }
}
