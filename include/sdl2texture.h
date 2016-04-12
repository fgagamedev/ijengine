#pragma once
#include <iostream>
#include <SDL2/SDL.h>

namespace ijengine {

    class SDL2Texture {
    public:
        SDL2Texture(std::string file_path, SDL_Renderer *actual_renderer);
        int w;
        int h;
        bool valid_texture();
        void load_texture_from_path();
        ~SDL2Texture();
        void update();

    private:
        std::string file_name;
        SDL_Renderer *renderer;
        SDL_Texture *sdl_texture;
    };
}
