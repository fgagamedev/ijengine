#ifndef IJENGINE_INPUT_H
#define IJENGINE_INPUT_H

#include "system_input.h"
#include "keyboard_input.h"

namespace ijengine {

    static const unsigned char UNKNOWN_INPUT = 0x00;

    struct _Input {
        unsigned timestamp;

        union {
            unsigned char type;
            SystemInput system;
            KeyboardInput keyboard;
        }; 

        _Input(unsigned t) : timestamp(t) {}
    };

    typedef struct _Input Input;
}

#endif
