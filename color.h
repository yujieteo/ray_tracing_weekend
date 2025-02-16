#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

using color = vec3;

void write_color(std::ostream& out, const color& pixel_color) {
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();


	// Translate unit length [0,1] component values to byte range.
	// This feels like functional analysis already sort of.
	int rbyte = int(255.999 * r);
	int gbyte = int(255.999 * g);
	int bbyte = int(255.999 * b);

	// write out pixel components
	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif
