#ifndef IJENGINE_GL_H
#define IJENGINE_GL_H

#include "libs.h"

namespace ijengine {

    class LibGL : public Lib {
    public:
        ~LibGL();

        string name() const;
        string version() const;

        void config(const string& param, const string& value);
        void init();
    };

}

#endif
