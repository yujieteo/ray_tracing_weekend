// NOTE I AM USING COMMENTS BECAUSE THIS IS MEANT TO BE A LEARNING PROJECT AFTER ALL.

#include "color.h"
#include "vec3.h"
#include "ray.h"

// why is .h is at the top .h

#include <iostream>

color ray_color(const ray& r) {
	vec3 unit_direction = unit_vector(r.direction());

	auto a  = 0.5 * (unit_direction.y() + 1.0);

	// linear blend or linear combination
	// in probability this just called a convex combination

	return (1.0 - a) * color(1.0,1.0,1.0) + a*color(0.5,0.7,1.0);
}

int main() {
	auto aspect_ratio = 16.0 / 9.0;

	// I tried this and I didn't realise how inefficient the .ppm format.
	int image_width = 2140;

	// calculate image height, ensure it is at least 1.
	// wait this can fail?

	int image_height = int(image_width / aspect_ratio);
	
	// if true < 1 force it to be 1 otherwise
	image_height = (image_height < 1) ? 1 : image_height;

	// CAMERA!!!
	
	auto focal_length = 1.0;
	auto viewport_height = 2.0;

	auto viewport_width = viewport_height * (double(image_width)/image_height);

	auto camera_center = point3(0, 0, 0);

	// Calculate the linear vectors across the horizontal and vertical viewport edges.

	auto viewport_u = vec3(viewport_width, 0, 0);
	auto viewport_v = vec3(0, -viewport_height, 0);

	// Calculate the horizontal and vertical delta vectors from pixel to pixel. This is the infinitesimal vector.

	auto pixel_delta_u = viewport_u / image_width;
	auto pixel_delta_v = viewport_v / image_height;

	// Calculate the location of the upper left pixel of the camera.

	auto viewport_upper_left = camera_center 
	- vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;

	auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

	// Render

	// int image_width = 256;
	// int image_height = 256;
	// Need this so that the subtraction is normal.
	// I did ``.\main.exe > image.ppm``x, did not know you can do this.

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0; j < image_height; j++) {
		std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
		for (int i = 0; i < image_width; i++)
			{
				// set the pixel camera
				auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);

				auto ray_direction = pixel_center - camera_center;

				ray r(camera_center, ray_direction);

				// Note that at this point of the tutorial, ray color will have to be filled in.
				color pixel_color = ray_color(r);

				// deliberate swap to make the same blue red lighting
				// auto pixel_color = color(double(i)/// ''(image_width - 1), 0, double(j)/(image_height - 1));

				write_color(std::cout, pixel_color);
				// This is sloppy. But what works, work. Ship fast.
				// auto r = double(i) / (image_width - 1);
				// I swapped here, this is a deviation from the original code.
				// auto b = double(j) / (image_height - 1);
				// auto g = 0.0;
				// int ir = int(255.999 * r);
				// int ig = int(255.999 * g);
				// int ib = int(255.999 * b);
				// std::cout << ir << ' ' << ig << ' ' << ' ' << ib << '\n';
			}
	}

	std::clog << "\rDone.                  \n";
}