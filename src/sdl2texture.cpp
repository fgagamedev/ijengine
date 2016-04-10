#include "sdl2texture.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace ijengine {

    SDL2Texture::SDL2Texture(std::string file_path, SDL_Renderer *actual_renderer) :
        file_name(file_path),
        renderer(actual_renderer)
    {
        if (valid_texture()) {
            load_texture_from_path();
        }
    }

    bool
    SDL2Texture::valid_texture()
    {
        bool valid = true;
        if (file_name.empty()) {
            valid = false;
        }

        if (renderer == nullptr) {
            valid = false;
        }

        return valid;
    }

    void
    SDL2Texture::load_texture_from_path()
    {
        SDL_Surface *surface_from_img = IMG_Load(file_name.c_str());
        SDL_Texture *texture_from_surface = nullptr;

        if (surface_from_img != nullptr) {
            texture_from_surface = SDL_CreateTextureFromSurface(renderer, surface_from_img);
            if (texture_from_surface != nullptr) {
                w = surface_from_img->w;
                h = surface_from_img->h;

                sdl_texture = texture_from_surface;
            } else {
                std::cout << SDL_GetError() << std::endl;
            }

            SDL_FreeSurface(surface_from_img);
        } else {
            std::cout << SDL_GetError() << std::endl;
        }
    }

    SDL2Texture::~SDL2Texture()
    {
        if (sdl_texture != nullptr) {
            SDL_DestroyTexture(sdl_texture);
        }
    }

    void
    SDL2Texture::update()
    {
        if (renderer != nullptr) {
            SDL_RenderCopy(renderer, sdl_texture, nullptr, nullptr);
        }
    }
}
