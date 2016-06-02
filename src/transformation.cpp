#include "math3D.h"
#include "transformation.h"
#include <math.h>
#include <iostream>

using namespace std;

namespace ijengine{
	Transformation::Transformation(){
		loadIdentity(m_Trans);
		loadIdentity(m_Scale);
		loadIdentity(m_RotX);
		loadIdentity(m_RotY);
		loadIdentity(m_RotZ);
		loadIdentity(m_Perspective);
	}
	Transformation::~Transformation(){
		
	}
	void
	Transformation::loadIdentity(matrix4f& Trans){
		Trans = {1, 0, 0, 0,
				 0, 1, 0, 0,
				 0, 0, 1, 0,
				 0, 0, 0, 1}; 
	}
	void
	Transformation::setTranslation(float x, float y, float z){
		m_Trans.m[0][3] = x;
		m_Trans.m[1][3] = y;
		m_Trans.m[2][3] = z;
		printMatrix(m_Trans);
	}
	void
	Transformation::setRotationX(float angle){
		m_RotX.m[1][1] = cos(angle);
		m_RotX.m[2][1] = -sin(angle);
		m_RotX.m[1][2] = sin(angle);
		m_RotX.m[2][2] = cos(angle);
		printMatrix(m_RotX);
	}
	void
	Transformation::setRotationY(float angle){
		m_RotY.m[0][0] = cos(angle);
		m_RotY.m[0][2] = sin(angle);
		m_RotY.m[2][0] = -sin(angle);
		m_RotY.m[2][2] = cos(angle);
		printMatrix(m_RotY);
	}
	void
	Transformation::setRotationZ(float angle){
		m_RotZ.m[0][0] = cos(angle);
		m_RotZ.m[0][1] = sin(angle);
		m_RotZ.m[1][0] = -sin(angle);
		m_RotZ.m[1][1] = cos(angle);
		printMatrix(m_RotZ);
	}
	void
	Transformation::setScale(float scale){
		m_Scale.m[0][0] = scale;
		m_Scale.m[1][1] = scale;
		m_Scale.m[2][2] = scale;
		printMatrix(m_Scale);
	}

	void
	Transformation::setPerspective(float near, float far, float angle, float width, float height){
		m_Perspective.m[0][0] = 1/((width/height)*tan(angle/2));
		m_Perspective.m[1][1] = 1/(tan(angle/2));
		m_Perspective.m[2][2] = (-near-far)/(near-far);
		m_Perspective.m[2][3] = (2*(near*far))/(near-far);
		printMatrix(m_Perspective);
	}

	void
	Transformation::printMatrix(matrix4f matrix){
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j)
				cout << matrix.m[i][j] << " ";
			cout << endl;
		}
	}

	matrix4f 
	Transformation::getTransformation(){
		matrix4f Trans;
		// Trans = Mult(m_RotX, m_Scale);
		//Mult(m_Trans ,Mult(m_RotZ ,Mult(m_RotY ,(Mult(m_RotX, m_Scale))));
		return Trans;
	}
}