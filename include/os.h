#ifndef IJENGINE_OS_H
#define IJENGINE_OS_H

#include <string>

using std::string;

namespace ijengine
{
    class Lib;
    
    namespace os
    {
        Lib * load_lib(const string& path);
    }    
}

#endif