/*
 * color.h
 *
 *  Created on: Apr 10, 2015
 *      Author: jsrolon
 */

#ifndef UTILS_COLOR_H_
#define UTILS_COLOR_H_

#include "berta.h"

class Color {
public:
	float r, g, b;

	Color();
	Color(float rr, float gg, float bb);

	Color powc(float p) const;

	Color operator/(const float a) const {
		return (Color (r / a, g / a, b / a));
	}

	virtual ~Color();
};

#endif /* UTILS_COLOR_H_ */