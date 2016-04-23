#include "sdl2kernel.h"
#include "exception.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace ijengine;


SDL2_Kernel::SDL2_Kernel()
{
    printf("Initializing kernel...\n");
    int rc = SDL_Init(SDL_INIT_VIDEO);

    if (rc)
        throw Exception("Error on SDL2_Kernel()");
}

SDL2_Kernel::~SDL2_Kernel()
{
    printf("Destroying kernel...\n");
    if (SDL_WasInit(SDL_INIT_VIDEO))
        SDL_Quit();
}

Window *
SDL2_Kernel::create_window(const string& title, int w, int h)
{
    return nullptr;
}