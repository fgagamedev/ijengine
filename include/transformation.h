#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include "math3D.h"

namespace ijengine {

    class Transformation {
    public:
    	Transformation();
       	~Transformation();
       	void setTranslation(float x, float y, float z);
       	void setRotationX(float angle);
       	void setRotationY(float angle);
       	void setRotationZ(float angle);
       	void setScale(float scale);
       	void setPerspective(float near, float far, float angle, float width, float height);
       	void setOrtogonal();
       	matrix4f getTransformation();
    private:
       	void printMatrix(matrix4f matrix);
    	matrix4f m_Trans;
    	matrix4f m_RotX;
    	matrix4f m_RotY;
    	matrix4f m_RotZ;
    	matrix4f m_Scale;
    	matrix4f m_Perspective;
    	void loadIdentity(matrix4f& Trans);

    };
}

#endif