#include <iostream>

int main() {
	int image_width = 256;
	int image_height = 256;
	// Need this so that the subtraction is normal.
	// I did ``.\main.exe > image.ppm``x, did not know you can do this.

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0; j < image_height; j++) {
		for (int i = 0; i < image_width; i++)
			{
				// This is sloppy. But what works, work. Ship fast.
				auto r = double(i) / (image_width - 1);
				
				auto b = double(j) / (image_height - 1);

				auto g = 0.0;

				int ir = int(255.999 * r);
				int ig = int(255.999 * g);
				int ib = int(255.999 * b);

				std::cout << ir << ' ' << ig << ' ' << ' ' << ib << '\n';
			}
	}
}