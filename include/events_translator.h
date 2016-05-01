#ifndef IJENGINE_EVENTS_TRANSLATOR_H
#define IJENGINE_EVENTS_TRANSLATOR_H

#include "event.h"
#include "game_event.h"

#include <map>
#include <list>
#include <string>
#include <utility>

using std::map;
using std::list;
using std::pair;
using std::string;

namespace ijengine
{
    class EventsTranslator
    {
    public:
        list<game_event_t> translate(list<event_t>& events) const;

        void add_translation(const Event& event, const GameEvent& gevent);

    private:
        map<string, string> m_translations;
    };
}

#endif
