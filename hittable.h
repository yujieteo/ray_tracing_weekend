#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class hit_record {
	public: 
		point3 p;
		vec3 normal;
		double t;
		bool front_face;

		void set_face_normal(const ray&r, const vec3& outward_normal) {
			// sets hit record normal vector.
			// IMPORTANT THE OUTWARD NORMAL IS ASSUMED TO HAVE UNTI LENGTH!!!

			front_face = dot(r.direction(), outward_normal) < 0;
			normal = front_face ? outward_normal : -outward_normal;
		}
};

// surface is not used, since volumes will be considered.
class hittable {
	public:
		virtual ~hittable() = default;

		virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

#endif