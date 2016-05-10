#include "shader_manager.h"
#include <fstream>
#include <vector>

using namespace std;

namespace ijengine {
    map<string, GLuint> ShaderManager::programs;
    ShaderManager::ShaderManager()
    {
        //Nada a ser feito
    }

    ShaderManager::~ShaderManager()
    {
      map<string, GLuint>::iterator i;
      for (i = programs.begin();i != programs.end(); ++i)
      {
        GLuint pr = i->second;
        glDeleteProgram(pr);
      }
      programs.clear();
    }

    void
    ShaderManager::CreateProgram (char *ShaderName, char *VertexShaderFileName,char *FragmentShaderFileName)
    {
        
       string vertex_shader_code = ReadShader(VertexShaderFileName);
       string fragment_shader_code = ReadShader(FragmentShaderFileName);
     
       GLuint vertex_shader = CreateShader(GL_VERTEX_SHADER, vertex_shader_code, "vertex shader");
      GLuint fragment_shader = CreateShader(GL_FRAGMENT_SHADER, fragment_shader_code, "fragment shader");
     
        int link_result = 0;
        //create the program handle, attatch the shaders and link it
        GLuint program = glCreateProgram();
        glAttachShader(program, vertex_shader);
        glAttachShader(program, fragment_shader);
     
        glLinkProgram(program);
        glGetProgramiv(program, GL_LINK_STATUS, &link_result);
        //check for link errors
        if (link_result == GL_FALSE)
        {
     
           int info_log_length = 0;
           glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_log_length);
           vector<char> program_log(info_log_length);
           glGetProgramInfoLog(program, info_log_length, NULL, &program_log[0]);
           cout << "Shader Loader : LINK ERROR" << endl << &program_log[0] << endl;
           return;
         }
       programs[ShaderName] = program;
    
    }
    const GLuint
    ShaderManager::GetShader(const std::string& shaderName)
    {
   
      return programs.at(shaderName);
 
    }
     string
    ShaderManager::ReadShader(char *filename)
    {
        string shaderCode;
        ifstream file(filename, ios::in);
     
        if(!file.good())
        {
           cout<<"Can't read file "<<filename<<endl;
           terminate();
        }
     
       file.seekg(0, ios::end);
       shaderCode.resize((unsigned int)file.tellg());
       file.seekg(0, ios::beg);
       file.read(&shaderCode[0], shaderCode.size());
       file.close();
       return shaderCode;
    }
    GLuint
     ShaderManager::CreateShader(GLenum shaderType, string source, char *shaderName)
     {
         int compile_result = 0;
 
         GLuint shader = glCreateShader(shaderType);
         const char *shader_code_ptr = source.c_str();
         const int shader_code_size = source.size();
     
         glShaderSource(shader, 1, &shader_code_ptr, &shader_code_size);
         glCompileShader(shader);
         glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_result);
     
         //check for errors
         if (compile_result == GL_FALSE)
         {
               int info_log_length = 0;
               glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);
               std::vector<char> shader_log(info_log_length);
               glGetShaderInfoLog(shader, info_log_length, NULL, &shader_log[0]);
               std::cout << "ERROR compiling shader: " << shaderName << std::endl << &shader_log[0] << std::endl;
               return 0;
     }
     return shader;
     }

}
