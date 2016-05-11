#ifndef IJENGINE_CANVAS_H
#define IJENGINE_CANVAS_H

#include "rectangle.h"
#include "point.h"
#include "line.h"

namespace ijengine {

    class Texture;

    class Canvas {
    public:
        virtual ~Canvas() = default;
        virtual void draw(const Texture *texture, int x, int y) = 0;
        virtual void draw(const Texture *texture, const Rectangle& section, int x, int y) = 0;
        virtual void drawRect(Rectangle rectangle, int r, int g, int b) = 0;
        virtual void drawPoint(Point point, int r, int g, int b) = 0;
        virtual void drawLine(Line line, int r, int g, int b) = 0;
        virtual void update() = 0;
        virtual void clear() = 0;
    };
}

#endif
