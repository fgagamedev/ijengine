#include "rectangle.h"

namespace ijengine
{
	Rectangle::Rectangle(int x, int y, int w, int h) :
		m_x(x), m_y(y), m_w(w), m_h(h)
	{
	}

    int
    Rectangle::x() const {
        return m_x;
    }

    int
    Rectangle::y() const {
        return m_y;
    }

    int
    Rectangle::w() const {
        return m_w;
    }

    int
    Rectangle::h() const {
        return m_h;
    }
}
