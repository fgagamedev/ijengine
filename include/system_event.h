#ifndef IJENGINE_SYSTEM_EVENT_H
#define IJENGINE_SYSTEM_EVENT_H

#include "event.h"

#define SYSTEM_EVENT_ID 0x01

#include <sstream>

using std::ostringstream;

namespace ijengine {

    class SystemEvent : public Event
    {
    public:
        typedef enum {QUIT, PAUSE} Action;

        SystemEvent(unsigned t, Action a) : Event(t), m_action(a) {}

        Action action() const { return m_action; }

        string serialize() const
        {
            ostringstream os;
            os << SYSTEM_EVENT_ID << "," << (int) m_action;

            return os.str();
        }

    private:
        Action m_action;
    };
}

#endif
