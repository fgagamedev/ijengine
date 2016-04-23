#ifndef IJENGINE_KERNEL_H
#define IJENGINE_KERNEL_H

#include <string>

using std::string;

namespace ijengine {

    class Window;
    
    class Kernel {
    public:
        virtual ~Kernel() {}
        virtual Window * create_window(const string& title, int w, int h) = 0;
    };
}

#endif
