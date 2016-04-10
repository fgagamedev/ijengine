#include "sdl2game.h"
#include "SDL2/SDL.h"

using namespace ijengine;

int main()
{
    SDL2Game game;

    int fail = game.run();

    if (not fail) {

        SDL_Event e;
        bool quit = false;

        while (not quit) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
            }
        }
    }

    return fail;
}
