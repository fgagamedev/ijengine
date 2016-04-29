#ifndef IJENGINE_EVENT_H
#define IJENGINE_EVENT_H

#include <string>

using std::string;

namespace ijengine {

    class Event {
    public:
        Event(unsigned t) : m_timestamp(t) {}
        virtual ~Event() = default;

        unsigned timestamp() const { return m_timestamp; }
        virtual string serialize() const = 0;

    private:
        unsigned m_timestamp;
    };
}

#endif
