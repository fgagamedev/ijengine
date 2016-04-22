#include "game.h"
#include "canvas.h"

#include <SDL2/SDL.h>

namespace ijengine {

    Game::~Game()
    {
    }

    int
    Game::run()
    {
        int counter = 0;

        Uint32 last = SDL_GetTicks();

        while (counter++ < 1000)
        {
            Uint32 now = SDL_GetTicks();

//            update(now, last);

            draw(now, last);
        }

        return 0;
    }

    void
    Game::draw(int now, int last)
    {
        Canvas *c = canvas();
        c->clear();
        // draw(c, now, last);
        c->update();
    }
}
