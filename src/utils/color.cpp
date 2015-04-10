/*
 * color.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: jsrolon
 */

#include <color.h>

Color::Color() :
		r(0), g(0), b(0) {
}

Color::Color(float rr, float gg, float bb) :
		r(rr), g(gg), b(bb) {
}

Color Color::powc(float p) const {
	return (Color(pow(r, p), pow(g, p), pow(b, p)));
}

Color::~Color() {
	// TODO Auto-generated destructor stub
}
