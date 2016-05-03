#include "game.h"
#include "level.h"
#include "window.h"
#include "canvas.h"
#include "engine.h"
#include "game_event.h"
#include "system_event.h"
#include "events_translator.h"

#include <SDL2/SDL.h>
#include <memory>
#include <cstdio>

using std::unique_ptr;
using namespace ijengine;

namespace ijengine {

    Game::Game(const string& title, int w, int h)
        : m_title(title), m_w(w), m_h(h), m_state(PAUSED)
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

        EventsTranslator translator;
        translator.add_translation(SystemEvent(0, SystemEvent::QUIT),
            GameEvent(GAME_EVENT_QUIT));
        event::register_translator(&translator);

        event::register_listener(this);
 
        m_state = RUNNING;

        int cnt = 0;
        while (m_state != QUIT)
        {
            if(cnt == 5000) {
                time::pause();
            }
            else if(cnt == 10000) {
                time::resume();
            }

            Uint32 now = time::time_elapsed();
            event::dispatch_pending_events(now);

            printf("now = %u   last = %u\n", now, last);

            level->update(now, last);

            canvas->clear();
            level->draw(canvas, now, last);
            canvas->update();

            if (level->done())
            {
                string next = level->next();
                delete level;
                level = Level::load(next);

                if (not level) m_state = QUIT;
            }

            last = now;
            cnt++;
        }

        return 0;
    }

    bool
    Game::on_event(const GameEvent& event)
    {
        if (event.type() == GAME_EVENT_QUIT)
        {
            m_state = QUIT;
            return true;
        }

        return false;
    }
}
