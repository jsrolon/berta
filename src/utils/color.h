/*
 * color.h
 *
 *  Created on: Apr 10, 2015
 *      Author: jsrolon
 */

#ifndef UTILS_COLOR_H_
#define UTILS_COLOR_H_

#include "berta.h"

/**
 * TODO implement multiplication
 */
class Color {
public:
	float r, g, b;

	Color();
	Color(float rr, float gg, float bb);

	Color powc(float p) const;

	Color operator/(const float a) const {
		return (Color (r / a, g / a, b / a));
	}

	Color operator*(const float a) const {
		return Color(r * a, g*a, b*a);
	}

	Color operator+=(const Color c) {
		r += c.r;
		g += c.g;
		b += c.b;
		return(*this);
	}

	virtual ~Color();
};

inline Color operator*(const float a, const Color c) {
	return Color(c.r*a,c.g*a,c.b*a);
}

#endif /* UTILS_COLOR_H_ */
