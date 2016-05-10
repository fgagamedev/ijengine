#ifndef IJENGINE_GLRENDERER3D_H
#define IJENGINE_GLRENDERER3D_H
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL.h>
#include "renderer3d.h"

using namespace ijengine;


class GLrenderer3d : public Renderer3d {
public:
    GLrenderer3d(SDL_Window *renderer3d);

   // void draw(const Texture *texture, int x, int y);
 //   void draw_from_rectangle(const Texture *texture, const SDL_Rect source, const SDL_Rect destiny);
   
    void drawTriangle(float x, float y, float z, float scale, int r, int g, int b);

    void notifyBeginframe();
    void notifyEndFrame();

    SDL_Window * renderer3d() const;

private:
    SDL_Window *m_renderer3d;
};

#endif
