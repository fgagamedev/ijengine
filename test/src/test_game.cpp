#include "test_game.h"

#include <ijengine/system_event.h>

TestGame::TestGame(const string& title, const string& audio_path, int w, int h)
    : m_game(title, audio_path, w, h), m_engine(), m_level_factory()
{
    m_translator.add_translation(SystemEvent(0, SystemEvent::QUIT),
        GameEvent(GAME_EVENT_QUIT));
    event::register_translator(&m_translator);

    level::register_factory(&m_level_factory);
}

TestGame::~TestGame()
{
    level::unregister_factory();
    event::unregister_translator(&m_translator);
}

int
TestGame::run(const string& level_id)
{
    return m_game.run(level_id);
}
