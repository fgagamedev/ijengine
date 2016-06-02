#ifndef MATH3D_H
#define MATH3D_H
#include "data_format.h"

namespace ijengine {

    class Math3D {
    public:
        ~Math3D() = default;
        matrix4f Mult(matrix4f Left, matrix4f Right);
    };
}

#endif