#include "line.h"

namespace ijengine
{
    Line::Line(int x1, int y1, int x2, int y2) :
        m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2)
    {
    }

    int
    Line::x1() const {
        return m_x1;
    }

    int
    Line::y1() const {
        return m_y1;
    }

    int
    Line::x2() const {
        return m_x2;
    }

    int
    Line::y2() const {
        return m_y2;
    }
}
