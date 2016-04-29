#include "game.h"
#include "level.h"
#include "window.h"
#include "canvas.h"
#include "engine.h"

#include <SDL2/SDL.h>
#include <memory>

using std::unique_ptr;
using namespace ijengine;

namespace ijengine {

    Game::Game(const string& title, int w, int h)
        : m_title(title), m_w(w), m_h(h)
    {
    }

    int
    Game::run(const string& level_id)
    {
        auto test = video::create_window(m_title, m_w, m_h);
        auto window = unique_ptr<Window>(test);
        
        if (not window)
            return -1;

        Canvas *canvas = window->canvas();
        Level *level = Level::load(level_id);
        Uint32 last = SDL_GetTicks();

        while (level)
        {
            Uint32 now = SDL_GetTicks();
            event::dispatch_pending_events(now);

            level->update(now, last);

            canvas->clear();
            level->draw(canvas, now, last);
            canvas->update();

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
}
