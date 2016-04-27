#include "exception.h"
#include "engine.h"
#include "kernel.h"
#include "lib.h"
#include "os.h"

#include <stdio.h>

namespace ijengine 
{
    static Kernel *kernel = nullptr;
    
    Engine::Engine()
    {
        auto files = os::list_files("libs");
        string path("");
        
        for (auto file : files)
            if (file.find("kernel") != string::npos) 
            {
                path = "libs/" + file;
                break;
            }
            
        if (path.size() == 0)
            throw Exception("Kernel not found in libs dir");
            
        m_kernel_lib = unique_ptr<Lib>(os::load_lib(path));
        
        if (not m_kernel_lib)
            throw Exception("Can't load kernel lib");
            
        auto sym = m_kernel_lib->symbol("create_kernel");
                          
        if (not sym)
            throw Exception("Invalid kernel: missing create_kernel()");
            
        Kernel * (*create)();
        *reinterpret_cast<void **>(&create) = sym;
        
        kernel = create();
        
        if (not kernel)
            throw Exception("Can't create the kernel");
    }
    
    Engine::~Engine()
    {
        auto sym = m_kernel_lib->symbol("destroy_kernel");
                          
        if (not sym)
            throw Exception("Invalid kernel: missing destroy_kernel()");
            
        void (*destroy)(Kernel *);
        *reinterpret_cast<void **>(&destroy) = sym;
        
        destroy(kernel);
    }
    
    namespace video 
    {
        Window *
        create_window(const string& title, int w, int h)
        {
            return kernel->create_window(title, w, h);
        }
    }

    namespace input
    {
        vector<Input *>
        pending_inputs(unsigned now)
        {
            return kernel->pending_inputs(now);
        }
    }
}
