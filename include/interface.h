#ifndef IJENGINE_INTERFACE_H
#define IJENGINE_INTERFACE_H

namespace ijengine {
    class Interface: public Renderer3d {
    public:
         ~Interface() = default;
         void drawTriangle(float x, float y, float z, float scale, int r, int g, int b) = 0;
         void notifyBeginframe() = 0;
         void notifyEndFrame() = 0;
    };
}

#endif