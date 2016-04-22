#include "test_level.h"
#include "canvas.h"

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
        canvas->drawRect(0, 0, 200, 200, m_r, m_g, m_b);
    }
}
