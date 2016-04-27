#ifndef IJENGINE_SYSTEM_INPUT_H
#define IJENGINE_SYSTEM_INPUT_H

#include "input.h"

namespace ijengine {

    class SystemInput : public Input
    {
    public:
        typedef enum {QUIT} Action;

        SystemInput(Action action);

        Action action() const;

    private:
        Action m_action;
    };
}

#endif
