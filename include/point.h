#ifndef IJENGINE_POINT_H
#define IJENGINE_POINT_H

namespace ijengine
{

    class Point {
    public:
        virtual ~Point() = default;
        Point(int x, int y);   

        int x() const;
        int y() const;

    private:
        int m_x;
        int m_y;
    };
}

#endif
