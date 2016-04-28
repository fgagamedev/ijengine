#ifndef IJENGINE_KERNEL_H
#define IJENGINE_KERNEL_H

#include <string>
#include <list>

using std::list;
using std::string;

#include "input.h"

namespace ijengine {

    class Window;
    
    class Kernel {
    public:
        virtual ~Kernel() {}
        virtual Window * create_window(const string& title, int w, int h) = 0;

        virtual list<Input> pending_inputs(unsigned now) = 0;
    };
}

#endif
