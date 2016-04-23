#ifndef IJENGINE_SDL2_KERNEL_H
#define IJENGINE_SDL2_KERNEL_H

#include "kernel.h"

using namespace ijengine;

class SDL2_Kernel : public Kernel {
public:
    SDL2_Kernel();
    ~SDL2_Kernel();
    
    Window * create_window(const string& title, int w, int h);
};

#endif
