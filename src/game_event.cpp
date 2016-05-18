#include "exception.h"
#include "game_event.h"

#include <sstream>

using std::istringstream;
using std::ostringstream;
using std::move;

namespace ijengine
{
    GameEvent::GameEvent(unsigned t, unsigned ts)
        : Event(ts), m_type(t)
    {
    }
    
    unsigned
    GameEvent::type() const
    {
        return m_type;
    }

    string
    GameEvent::serialize() const
    {
        ostringstream os;

        os << m_type;

        for (auto p : m_properties)
            os << "," << p.first << ":" << p.second;

        return os.str();
    }

    GameEvent
    GameEvent::deserialize(const string& data, unsigned timestamp)
    {
        istringstream is(data);
        string text;

        getline(is, text, ',');
        unsigned type = stoi(text);

        GameEvent event(type, timestamp);

        while (getline(is, text, ','))
        {
            auto pos = text.find(':');
            auto property = text.substr(0, pos);
            auto value = text.substr(pos + 1);

            event.set_property<string>(property, value);
        }

        return event;
    }
}
