#include "math3D.h"

using namespace std;

namespace ijengine{

	matrix4f
	Math3D::Mult(matrix4f Left, matrix4f Right){
		matrix4f Ret;
    	for (unsigned int i = 0 ; i < 4 ; i++) {
       		for (unsigned int j = 0 ; j < 4 ; j++) {
           		Ret.m[i][j] = Left.m[i][0] * Right.m[0][j] +
                        	  Left.m[i][1] * Right.m[1][j] +
                              Left.m[i][2] * Right.m[2][j] +
                          	  Left.m[i][3] * Right.m[3][j];
       		}
    	}
    	return Ret;
	}
}