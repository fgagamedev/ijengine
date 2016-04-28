#ifndef IJENGINE_ENGINE_H
#define IJENGINE_ENGINE_H

#include <list>
#include <string>
#include <memory>

using std::list;
using std::string;
using std::unique_ptr;

#include "input.h"

namespace ijengine {
    
    class Lib;
    class Window;
    
    class Engine {
    public:
        Engine();
        ~Engine();    
        
    private:
        unique_ptr<Lib> m_kernel_lib;
    };
    
    namespace video {
        Window * create_window(const string& title, int w, int h);
    }

    namespace input {
        list<Input> pending_inputs(unsigned now);
    }
}

#endif
