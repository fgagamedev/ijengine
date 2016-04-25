#include "sdl2kernel.h"
#include "sdl2window.h"
#include "exception.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace ijengine;


SDL2Kernel::SDL2Kernel()
{
    printf("Initializing kernel...\n");
    int rc = SDL_Init(SDL_INIT_VIDEO);

    if (rc)
        throw Exception("Error on SDL2Kernel()");
}

SDL2Kernel::~SDL2Kernel()
{
    printf("Destroying kernel...\n");
    if (SDL_WasInit(SDL_INIT_VIDEO))
        SDL_Quit();
}

Window *
SDL2Kernel::create_window(const string& title, int w, int h)
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    if (SDL_CreateWindowAndRenderer(w, h, 0, &window, &renderer))
        return nullptr;

    SDL_SetWindowTitle(window, title.c_str());

    return new SDL2Window(window, renderer);
}
