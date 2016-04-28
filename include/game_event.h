#ifndef IJENGINE_GAME_EVENT_H
#define IJENGINE_GAME_EVENT_H

#include <map>
#include <string>
#include <sstream>

using std::map;
using std::string;
using std::istringstream;
using std::ostringstream;

namespace ijengine
{
    class GameEvent
    {
    public:
        GameEvent(unsigned type);

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
                throw Exception("Invalid GameEvent property: " + property);

            istringstream is(m_properties.at(property));

            T value;
            is >> value;

            return value;
        }

    private:
        unsigned m_type;
        map<string, string> m_properties;

        bool validate(unsigned type);
    };

}

#endif
