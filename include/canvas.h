#ifndef IJENGINE_CANVAS_H
#define IJENGINE_CANVAS_H

namespace ijengine {

    class Texture;

    class Canvas {
    public:
        virtual ~Canvas() = default;
        virtual void draw(const Texture *texture, int x, int y) = 0;
        virtual void drawRect(int x, int y, int w, int h, int r, int g, int b) = 0;
        virtual void update() = 0;
        virtual void clear() = 0;
    };
}

#endif
