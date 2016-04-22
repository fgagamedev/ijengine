#ifndef TEST_LEVEL_H
#define TEST_LEVEL_H

#include "level.h"

#include <string>

using std::string;

namespace ijengine {

    class TestLevel : public Level {
    public:
        TestLevel(int r, int g, int b, const string& next = "");

        bool done() const;
        string next() const;

        void update(int now, int last);
        void draw(Canvas *canvas, int now, int last);

    private:
        int m_r, m_g, m_b;
        bool m_done;
        string m_next;
        int m_start;
    };

}

#endif
