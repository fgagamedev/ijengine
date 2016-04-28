#ifndef IJENGINE_SYSTEM_INPUT_H
#define IJENGINE_SYSTEM_INPUT_H

namespace ijengine {

    static const unsigned char SYSTEM_INPUT = 0x01;

    struct _SystemInput
    {
        typedef enum {QUIT} Action;

        _SystemInput(Action a) : 
            type(SYSTEM_INPUT), action(a) {}

        unsigned char type;
        unsigned char action;
    };

    typedef struct _SystemInput SystemInput;
}

#endif
