#ifndef IJENGINE_ENGINE_H
#define IJENGINE_ENGINE_H

#include <string>
#include <memory>
#include <vector>

using std::string;
using std::vector;
using std::unique_ptr;

namespace ijengine {
    
    class Lib;
    class Window;
    class Input;
    
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
        vector<Input *> pending_inputs(unsigned now);
    }
}

#endif
