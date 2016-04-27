#ifndef IJENGINE_INPUT_H
#define IJENGINE_INPUT_H

#include <string>

using std::string;

namespace ijengine {

    class Input {
    public:
        virtual ~Input() = default;

        virtual unsigned timestamp() const = 0;
    };

}

#endif
