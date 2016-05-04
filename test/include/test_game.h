#ifndef TEST_GAME_H
#define TEST_GAME_H

#include <ijengine/game.h>
#include <ijengine/engine.h>
#include <ijengine/events_translator.h>

using namespace ijengine;

class TestGame {
public:
    TestGame(const string& title, int w, int h);

    int run(const string& level_id);
private:
    Game m_game;
    Engine m_engine;
    EventsTranslator m_translator;
};

#endif
