#ifndef IJENGINE_SDL2_KERNEL_H
#define IJENGINE_SDL2_KERNEL_H

#include "kernel.h"

using namespace ijengine;

class SDL2Kernel : public Kernel {
public:
    SDL2Kernel();
    ~SDL2Kernel();
    
    Window * create_window(const string& title, int w, int h);

    list<Input> pending_inputs(unsigned now);
};

#endif
