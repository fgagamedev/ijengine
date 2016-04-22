#ifndef LEVEL_H
#define LEVEL_H

#include "gameobject.h"

#include <string>

using std::string;

namespace ijengine {

    class Level : public GameObject {
    public:
        virtual ~Level() {}

        virtual bool done() const = 0;
        virtual string next() const = 0;

        static Level * load(const string& level);
    };

}

#endif
