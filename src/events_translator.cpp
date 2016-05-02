#include "events_translator.h"

namespace ijengine
{
    list<game_event_t>
    EventsTranslator::translate(list<event_t>& events) const
    {
        list<game_event_t> game_events;
        auto it = events.begin();

        while (it != events.end())
        {
            unsigned timestamp = it->first;
            auto translation = m_translations.find(it->second);

            if (translation != m_translations.end())
            {
                game_events.push_back(game_event_t(timestamp,
                    translation->second));
                it = events.erase(it);
            } else
                ++it;
        }

        return game_events;
    }

    void
    EventsTranslator::add_translation(const Event& event,
        const GameEvent& game_event)
    {
        m_translations[event.serialize()] = game_event.serialize();
    }
}
