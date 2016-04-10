#include "sdl2game.h"
#include "SDL2/SDL.h"
#include <iostream>

using namespace ijengine;

int main()
{
    SDL2Game game;

    int fail = game.run();

    if (not fail) {
        SDL2Texture test_texture("test/img-test.png", game.m_video->renderer);

        SDL_Event e;
        bool quit = false;

        while (not quit) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
            }
            SDL_RenderClear(game.m_video->renderer);
            SDL_SetRenderDrawColor(game.m_video->renderer, 0xFF, 0xFF, 0xFF, 0xFF);

            test_texture.update();
            SDL_RenderPresent(game.m_video->renderer);
        }
    }

    return fail;
}
