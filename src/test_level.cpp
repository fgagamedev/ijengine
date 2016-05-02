#include "test_level.h"
#include "canvas.h"

#include <iostream>

using std::cout;
using std::endl;

namespace ijengine {

    TestLevel::TestLevel(int r, int g, int b, const string& next_level)
        : m_r(r), m_g(g), m_b(b), m_done(false), m_next(next_level), m_start(-1)
    {
    }

    bool
    TestLevel::done() const
    {
        return m_done;
    }
    
    string
    TestLevel::next() const
    {
        return m_next;
    }

    void
    TestLevel::update(int now, int)
    {
        if (m_start == -1)
            m_start = now;

        if (now - m_start > 1000)
            m_done = true;
    }

    void
    TestLevel::draw(Canvas *canvas, int, int)
    {
        Rectangle rectangle(100, 100, 200, 200);
        canvas->drawRect(rectangle, m_r, m_g, m_b);

        // Drawing many points so they can be visible on the scren...
        for(int i = 0; i < 100; i++) {
            Point point(300 + i, 300);
            canvas->drawPoint(point, m_r, m_g, m_b);
        }

        // Drawing test line
        Line line(100, 300, 100, 400);
        canvas->drawLine(line, m_r, m_g, m_b);
    }
}
