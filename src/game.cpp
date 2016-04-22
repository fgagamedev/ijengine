#include "game.h"
#include "level.h"
#include "canvas.h"

#include <SDL2/SDL.h>

namespace ijengine {

    Game::~Game()
    {
    }

    int
    Game::run(const string& level_id)
    {
        Level *level = Level::load(level_id);
        Uint32 last = SDL_GetTicks();

        while (level)
        {
            Uint32 now = SDL_GetTicks();

            level->update(now, last);

            draw(level, now, last);

            if (level->done())
            {
                string next = level->next();
                delete level;
                level = Level::load(next);
            }

            last = now;
        }

        return 0;
    }

    void
    Game::draw(Level *level, int now, int last)
    {
        Canvas *c = canvas();
        c->clear();
        level->draw(c, now, last);
        c->update();
    }
}
