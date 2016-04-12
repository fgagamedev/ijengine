#include "sdl2.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_version.h>

#include <iostream>
using namespace std;

namespace ijengine {

    LibSDL2::~LibSDL2()
    {
printf("Desligando a SDL2...\n");
        if (SDL_WasInit(IMG_INIT_PNG)) {
            IMG_Quit();
        }

        if (SDL_WasInit(SDL_INIT_VIDEO)) {
            SDL_Quit();
        }
    }

    string
    LibSDL2::name() const
    {
        return "SDL2";
    }

    string
    LibSDL2::version() const
    {
        SDL_version v;
        SDL_GetVersion(&v);

        char buffer[128];
        sprintf(buffer, "%d.%d.%d", v.major, v.minor, v.patch);

        return string(buffer);
    }

    void
    LibSDL2::config(const string&, const string&)
    {
    }

    void
    LibSDL2::init()
    {
        int rc = SDL_Init(SDL_INIT_VIDEO);

        if (rc)
            throw "Error on LibSDL2::init()";

        IMG_Init(IMG_INIT_PNG);
printf("nome = [%s], versao = [%s]\n", name().c_str(), version().c_str());
    }

}
