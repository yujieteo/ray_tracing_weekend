#include "color.h"
#include "vec3.h"

// why is .h is at the top .h

#include <iostream>

int main() {
	int image_width = 256;
	int image_height = 256;
	// Need this so that the subtraction is normal.
	// I did ``.\main.exe > image.ppm``x, did not know you can do this.

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0; j < image_height; j++) {
		std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
		for (int i = 0; i < image_width; i++)
			{

				// deliberate swap to make the same blue red lighting
				auto pixel_color = color(double(i)/(image_width - 1), 0, double(j)/(image_height - 1));

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