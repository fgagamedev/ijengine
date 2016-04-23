#ifndef IJENGINE_SDL2_H
#define IJENGINE_SDL2_H

#include "libs.h"

namespace ijengine {

    class LibSDL2 : public Lib {
    public:
        LibSDL2() {} 
        ~LibSDL2() {}

        string name() const { return ""; }
        string version() const { return ""; }

        void config(const string& param, const string& value) {}
        void init() {}
    };

}

#endif
