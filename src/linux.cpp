#include "os.h"
#include "lib.h"
#include "exception.h"

#include <dlfcn.h>

namespace ijengine
{
    namespace os
    {
        Lib *
        load_lib(const string& path)
        {
            void *handle = dlopen(path.c_str(), RTLD_LAZY |
                RTLD_GLOBAL);
            
            if (not handle)
                throw Exception(string("os::load_lib(): ") + dlerror());
                
            return new Lib(handle, dlclose);
        }
    }
}