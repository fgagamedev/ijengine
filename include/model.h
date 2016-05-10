#ifndef IGAME_OBJECT_H
#define IGAME_OBJECT_H

#include <vector> 
#include <iostream>
#include "GL/glew.h"
using namespace std;
namespace ijengine {
	class Model:public IGameObject
	{
	public:
		virtual ~IGameObject()=0;
		virtual void Draw() = 0 ;
		virtual Update() = 0;
		virtual void SetProgram(GLuint shaderName) = 0;
		virtual void Destroy();
		virtual GLuint GetVAO() const = 0;
		virtual const vector<GLuint>& GetVbos() const = 0;
	};
	
}

#endif
