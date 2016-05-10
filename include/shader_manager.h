#ifndef GLSHADERLOADER_H
#define GLSHADERLOADER_H

#include "shaderloader.h"
#include <iostream>
#include <map>
#include <GL/glew.h>
#include <GL/gl.h>

using namespace std;
namespace ijengine {

    class ShaderManager {
    public:
         ShaderManager();
         ~ShaderManager();
         void  CreateProgram (char *ShaderName, char *VertexShaderFileName,
        							char *FragmentShaderFileName);
         static const GLuint GetShader(const string& shaderName);
     private:
     	string ReadShader (char *filename);
     	GLuint CreateShader(GLenum shaderType, string source, char *shaderName);
        static map <string, GLuint> programs;
    };

}

#endif
