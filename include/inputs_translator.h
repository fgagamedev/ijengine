#ifndef IJENGINE_INPUTS_TRANSLATOR_H
#define IJENGINE_INPUTS_TRANSLATOR_H

#include "input.h"
#include "game_event.h"

#include <map>
#include <list>

using std::map;
using std::list;

namespace ijengine
{
    class InputTranslator
    {
    public:
        list<GameEvent> translate(list<Input>& inputs) const;

        void add_input(const Input& input, const GameEvent& event);

    private:
        map<Input, GameEvent> m_inputs;
    };
}

#endif
