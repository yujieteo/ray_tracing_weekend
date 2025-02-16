#ifndef RAY_H
#define RAY_H

#include "vec3.h"

// ray::origin()
// ray::direction()

// idea of the ray is based on an affine transformation.

class ray {
	public:

	ray() {}

	// for physicists these are linear interpolations
	// however, this is a sor tof affine line.
	// actually these are all vector spaces
	// with the completion of lines...
	ray(const point3& origin, const vec3&direction) : orig(origin), dir(direction) {}

	const point3& origin() const { return orig;}

	const vec3& direction() const { return dir;}

	point3 at(double t) const {
		return orig + t * dir;
	}

	private:
		point3 orig;
		vec3 dir;
};

#endif