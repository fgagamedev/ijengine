#ifndef IJENGINE_RENDERER3D_H
#define IJENGINE_RENDERER3D_H

namespace ijengine {
    class Renderer3d {
    public:
        virtual ~Renderer3d() = default;
     //   virtual void draw(const Texture *texture, int x, int y) = 0;
        virtual void drawTriangle(float x, float y, float z, float scale, int r, int g, int b) = 0;
        virtual void notifyBeginframe() = 0;
        virtual void notifyEndFrame() = 0;
    };
}

#endif
