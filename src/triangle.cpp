#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/glext.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "triangle.h"

namespace ijengine {

	Triangle::CreateTriangleModel(const string& gameModelName){
		Vector3f Vertices[3];
    	Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
    	Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
    	Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);

    	

 		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	}

}