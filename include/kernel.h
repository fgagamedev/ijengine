#ifndef IJENGINE_KERNEL_H
#define IJENGINE_KERNEL_H

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace ijengine {

    class Window;
    class Input;
    
    class Kernel {
    public:
        virtual ~Kernel() {}
        virtual Window * create_window(const string& title, int w, int h) = 0;

        virtual vector<Input *> pending_inputs(unsigned now) = 0;
    };
}

#endif
