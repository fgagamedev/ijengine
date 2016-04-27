#include "system_input.h"

namespace ijengine
{
    SystemInput::SystemInput(SystemInput::Action a)
        : m_action(a)
    {
    }

    SystemInput::Action
    SystemInput::action() const
    {
        return m_action;
    }
}
