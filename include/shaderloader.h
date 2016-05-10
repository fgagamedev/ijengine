#ifndef SHADERLOADER_H
#define SHADERLOADER_H

namespace ijengine {

    class ShaderLoader{
    public:
        virtual ~ShaderLoader();
        virtual void CreateProgram (char *ShaderName, char *VertexShaderFileName,
        							char *FragmentShaderFileName);

    };

}

#endif
