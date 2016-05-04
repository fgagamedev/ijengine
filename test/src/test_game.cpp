#include "test_game.h"

#include <ijengine/system_event.h>

TestGame::TestGame(const string& title, int w, int h)
    : m_game(title, w, h), m_engine()
{
    m_translator.add_translation(SystemEvent(0, SystemEvent::QUIT),
        GameEvent(GAME_EVENT_QUIT));
    event::register_translator(&m_translator);
}

int
TestGame::run(const string& level_id)
{
    return m_game.run(level_id);
}
