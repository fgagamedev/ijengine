/*#include "inputs_translator.h"

namespace ijengine
{
    list<event_t>
    InputsTranslator::translate(list<input_t>& inputs) const
    {
        list<event_t> events;
 
        auto it = inputs.begin();

        while (it != inputs.end())
        {
            unsigned timestamp = it->first;
            
            auto event = m_inputs.find(it->second);

            if (event != m_inputs.end())
            {
                events.push_back(event_t(timestamp, event->second));
                it = inputs.erase(it);
            } else
                ++it;
        }

        return events;
    }

    void
    InputsTranslator::add_input(const Input& input, const GameEvent& event)
    {
        m_inputs[input] = event;
    }
}
*/
