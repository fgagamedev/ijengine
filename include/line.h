#ifndef IJENGINE_LINE_H
#define IJENGINE_LINE_H

namespace ijengine
{
    class Line {
    public:
        virtual ~Line() = default;
        Line(int x1, int y1, int x2, int y2);

        int x1() const;
        int y1() const;
        int x2() const;
        int y2() const;

    private:
        int m_x1;
        int m_y1;
        int m_x2;
        int m_y2;
    };
}

#endif
