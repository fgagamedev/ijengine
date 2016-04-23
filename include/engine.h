#ifndef IJENGINE_ENGINE_H
#define IJENGINE_ENGINE_H

#include <memory>

using std::unique_ptr;

namespace ijengine {
    
    class Lib;
    
    class Engine {
    public:
        Engine();
        ~Engine();    
        
    private:
        unique_ptr<Lib> m_kernel_lib;
    };
    
    namespace video {
        
        void make_video();
    }
}

#endif