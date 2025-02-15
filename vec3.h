#ifndef VEC3_H

#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
	public:
		// orthonormal vector
		double e[3];
		
		vec3(): e{0,0,0} {}
		vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

		// return x, y, z coordinates
		double x() const { return e[0]; }
		double y() const { return e[1]; }
		double z() const { return e[2]; }

		// operator for --
		vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

		// These are pointers and addressing?
		double operator[](int i) const { return e[i]; }
		double& operator[](int i) {return e[i];}
	};

#endif