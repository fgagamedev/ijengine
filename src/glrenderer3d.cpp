
#include "glrenderer3d.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <iostream>

#include <SDL2/SDL.h>


GLrenderer3d::GLrenderer3d(SDL_Window *r) //initialization
    : m_renderer3d(r)
{
		glEnable(GL_DEPTH_TEST);
}

void
GLrenderer3d::drawTriangle(float x, float y, float z, float scale, int r, int g, int b)
{
	
}


void
GLrenderer3d::notifyBeginframe()
{
    printf("notifybeginframe\n");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
}


void
GLrenderer3d::notifyEndFrame()
{
	printf("notifyEndFrame\n");
     SDL_GL_SwapWindow(m_renderer3d);
}

SDL_Window *
GLrenderer3d::renderer3d() const
{
    return m_renderer3d;
}



