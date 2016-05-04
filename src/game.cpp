#include "game.h"
#include "level.h"
#include "window.h"
#include "canvas.h"
#include "engine.h"
#include "game_event.h"

#include <memory>

using std::unique_ptr;
using namespace ijengine;

namespace ijengine {

    Game::Game(const string& title, int w, int h)
        : m_title(title), m_w(w), m_h(h), m_state(PAUSED)
    {
        event::register_listener(this);
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
        unsigned last = time::time_elapsed();

        m_state = RUNNING;

        while (m_state != QUIT)
        {
            unsigned now = time::time_elapsed();
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

                if (not level) m_state = QUIT;
            }

            last = now;
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
