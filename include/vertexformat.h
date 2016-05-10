#ifndef VERTEX_FORMAT_H
#define VERTEX_FORMAT_H

namespace ijengine {
	struct Vector3f{
		float x;
		float y;
		float z;
		float r;
		float g;
		float b;
		Vector3f(){}
		Vector3f(float _x, float _y, float _z){
			x = _x;
			y = _y;
			z = _z;
			r = 0.5;
			g = 0.5;
			b = 0.5;
		}
		Vector3f(float _x, float _y, float _z, float _r, float _g, float _b){
			x = _x;
			y = _y;
			z = _z;
			r = _r;
			g = _g;
			b = _b;
		}
	};
}

#endif
