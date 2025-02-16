#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
	public:
	// don't understand this line, this returns the max of two arguments?
	// is it because there is a lack of orthogonality in the code?
		sphere(const point3& center, double radius) : center(center), radius(std::fmax(0,radius)) {}

	bool hit(const ray&r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
		// set up the centre properly, note that initially it was affine.
		vec3 oc = center - r.origin();

		// same abstraction for quadratic forms
		auto a = r.direction().length_squared();
		auto h = dot(r.direction(), oc);
		auto c = oc.length_squared() - radius*radius;
		auto discriminant = h*h - a*c;

		if (discriminant < 0) {
			return false;
		}

		auto sqrtd = std::sqrt(discriminant);

		auto root = (h - sqrtd) / a;

		if (root <= ray_tmin || ray_tmax <= root) {
			root = (h + sqrtd) / a;
			if (root <= ray_tmin || ray_tmax <= root) {
				return false;
			}
		}


		// what on earth this is doing, is it calculating some sort of tangency?
		rec.t = root;
		rec.p = r.at(rec.t);
		// rec.normal = (rec.p - center) / radius;
		vec3 outward_normal = (rec.p - center) / radius;
		rec.set_face_normal(r, outward_normal);

		// this checks that the thing is being done.
		return true;
	}

	private:

	point3 center;
	double radius;
};

#endif