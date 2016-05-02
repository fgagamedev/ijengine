#include "point.h"

namespace ijengine
{
    Point::Point(int x, int y) :
        m_x(x), m_y(y)
    {
    }

    int
    Point::x() const {
        return m_x;
    }

    int
    Point::y() const {
        return m_y;
    }
}
