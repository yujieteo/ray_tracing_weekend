#ifndef VEC3_H

#define VEC3_H

#include <cmath>
#include <iostream>

// double or float, float has greater precision and range,
// but twice the size of float. Hardware shaders have limited
// memory. I have used float here to make it slightly different.

class vec3 {
	public:
		// orthonormal vector
		float e[3];
		
		vec3(): e{0,0,0} {}
		vec3(float e0, float e1, float e2) : e{e0, e1, e2} {}

		// return x, y, z coordinates
		float x() const { return e[0]; }
		float y() const { return e[1]; }
		float z() const { return e[2]; }

		// operator for --
		vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

		// These are pointers and addressing?
		float operator[](int i) const { return e[i]; }
		float& operator[](int i) {return e[i];}

		// increment operator, with some sort of addressing.
		// This is a pointer address class...
		vec3& operator+=(const vec3 &v) {
			e[0] += v.e[0];
			e[1] += v.e[1];
			e[2] += v.e[2];
			
			// return the value associated with the pointer?
			return *this;
		}

		// inplace multiplication operator
		vec3& operator*=(float t) {
			e[0] *= t;
			e[1] *= t;
			e[2] *= t;

			return *this;
		}

		vec3& operator/=(float t) {
			return *this *= 1/t;
		}

		float length() const {
			return std::sqrt(length_squared());
		}

		float length_squared() const {
			return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
		}
		
	};

// alias for geometric clarity in the code

using point3 = vec3;

// vector utility functions

// print with space, see ostream

inline std::ostream& operator<<(std::ostream& out, const vec3&v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// pointwise addition
inline vec3 operator+(const vec3& u, const vec3& v) {
	return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// pointwise subtraction
inline vec3 operator-(const vec3& u, const vec3& v) {
	return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// seriously this feels like functional analysis
// inner product (norm)
inline vec3 operator*(const vec3& u, const vec3& v) {
	return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// same operator used for usage orthogonality
// so type is used to distinguish what this is actually doing
// scalar multiplication
inline vec3 operator*(float t, const vec3& v) {
	return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3&v, float t) {
	return t * v;
}

inline vec3 operator/(const vec3&v, float t) {
	return (1/t) * v;
}

inline float dot(const vec3&u, const vec3&v) {
	return 		u.e[0] * v.e[0]
			+ 	u.e[1] * v.e[1]
			+	u.e[2] * v.e[2];
}

// cross product directly by minors
inline vec3 cross(const vec3&u, const vec3&v) {
	return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
				u.e[2] * v.e[0] - u.e[0] * v.e[2],
				u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// norm for origin, note that there is no check for 0 length even though the natural group structure of SO(3) has a higher dimensional hole in the middle?

inline vec3 unit_vector(const vec3& v) {
	return v / v.length();
}

#endif