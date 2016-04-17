#include "libgl.h"

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
using namespace std;

namespace ijengine {

    LibGL::~LibGL()
    {
    printf("Desligando a GL...\n");
        
    }

    string
    LibGL::name() const
    {
        return "GL";
    }

    string
    LibGL::version() const
    { 
        GLint major, minor;
        const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
        glGetIntegerv(GL_MAJOR_VERSION, &major);
        glGetIntegerv(GL_MINOR_VERSION, &minor);
        char buffer[128]; 
        sprintf(buffer, "%s", glslVersion);
        return string(buffer);
    }

    void
    LibGL::config(const string& param, const string& value)
    {
        if (glewIsSupported(param.c_str()))
            printf("Ready for use: %s \nShader version %s\n",param.c_str(), value.c_str());
        else {
            throw "\n Opengl not supported\n";
        }
    }

    void
    LibGL::init()
    {
        
       GLenum res = glewInit();
        if (res != GLEW_OK) 
              printf("Error on LibGL::init() %i\n", res);
        printf("nome = [%s], versao shader suportada = [%s]\n", name().c_str(), version().c_str());
    }

}
