#include "test_level.h"
#include "random_rect.h"

#include <ijengine/canvas.h>

using namespace std;
using namespace ijengine;

TestLevel::TestLevel(int r, int g, int b, const string& next_level)
    : m_r(r), m_g(g), m_b(b), m_done(false), m_next(next_level), m_start(-1)
{
    RandomRect *rect1 = new RandomRect(r, g, b, 200, 200);
    RandomRect *rect2 = new RandomRect(0, 0, 0, 100, 100);
    
    rect1->add_children(rect2); 
    add_children(rect1); 
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
TestLevel::update_self(unsigned now, unsigned)
{
    if (m_start == -1)
        m_start = now;

    if (now - m_start > 1000)
        m_done = true;
}

void
TestLevel::draw_self(Canvas *canvas, unsigned, unsigned)
{
    canvas->clear();
}
