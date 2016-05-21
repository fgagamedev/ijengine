#ifndef TEST_GAME_H
#define TEST_GAME_H

#include <ijengine/game.h>
#include <ijengine/engine.h>
#include <ijengine/system_event.h>
#include <ijengine/events_translator.h>

#include "test_level_factory.h"

using namespace ijengine;

class TestGame {
public:
    TestGame(const string& title, int w, int h);
    ~TestGame();

    int run(const string& level_id);

private:
    class Translator : public EventsTranslator
    {
        bool
        translate(GameEvent& to, const MouseEvent& from) { return false; }

        bool
        translate(GameEvent& to, const SystemEvent& from)
        {
            if (from.action() == SystemEvent::QUIT)
            {
                to.set_timestamp(from.timestamp());
                to.set_id(game_event::QUIT);

                return true;
            }

            return false;
        }

        virtual bool
        translate(GameEvent& to, const KeyboardEvent& from) { return false; }
    };

    Game m_game;
    Engine m_engine;
    TestLevelFactory m_level_factory;
    Translator m_translator;
};

#endif
