#include "events_translator.h"

namespace ijengine
{
    list<game_event_t>
    EventsTranslator::translate(list<event_t>& events) const
    {
printf("Translation starting...\n");
        list<game_event_t> game_events;
 
        auto it = events.begin();

        while (it != events.end())
        {
            unsigned timestamp = it->first;
            auto translation = m_translations.find(it->second);
            if (translation != m_translations.end())
            {
printf("Translation: Find [%s] on %u\n", translation->second.c_str(), timestamp);
                GameEvent game_event = GameEvent::deserialize(translation->second, timestamp);
printf("res  = [%s]\n", game_event.serialize().c_str());
                game_events.push_back(game_event_t(timestamp, game_event));
printf("pushed\n");
                it = events.erase(it);
printf("erased\n");
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
