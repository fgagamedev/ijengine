#ifndef IJENGINE_GAME_EVENT_H
#define IJENGINE_GAME_EVENT_H

#include "event.h"
#include "exception.h"
#include "game_events_listener.h"

#include <map>
#include <string>
#include <sstream>

using std::map;
using std::pair;
using std::string;
using std::istringstream;
using std::ostringstream;

namespace ijengine
{
    #define GAME_EVENT_QUIT     0x01
    #define GAME_EVENT_PAUSE    0x02

    class GameEvent : public Event
    {
    public:
        GameEvent(unsigned type, unsigned timestamp = 0);

        unsigned type() const;

        template<typename T>
        void set_property(const string& property, const T& value)
        {
            ostringstream os;
            os << value;

            m_properties[property] = os.str();        
        }

        template<typename T>
        T get_property(const string& property) const
        {
            if (m_properties.find(property) == m_properties.end())
                throw Exception("Invalid GameEvent property" + property);

            istringstream is(m_properties.at(property));

            T value;
            is >> value;

            return value;
        }

        string serialize() const;
        static GameEvent deserialize(const string& data, unsigned timestamp);

    private:
        unsigned m_type;
        map<string, string> m_properties;

        bool validate(unsigned type);
    };

    using game_event_t = pair<unsigned, string>;
}

#endif
