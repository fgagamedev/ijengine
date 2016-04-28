#include "exception.h"
#include "game_event.h"

namespace ijengine
{
    GameEvent::GameEvent(unsigned t)
        : m_type(t)
    {
        if (not validate(m_type))
            throw Exception("Invalid GameEvent type");
    }
    
    unsigned
    GameEvent::type() const
    {
        return m_type;
    }

    bool
    GameEvent::validate(unsigned t)
    {
        return t and (t & (t - 1)) == 0;
    }
}
