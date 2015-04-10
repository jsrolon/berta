/*
 * viewplane.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: jsrolon
 */

#include <viewplane.h>

ViewPlane::ViewPlane() :
		hres(400), vres(400), pxSize(1.0), gamma(1.0), invGamma(1.0), show_out_of_gamut(
				true) {
}

ViewPlane::~ViewPlane() {
	// TODO Auto-generated destructor stub
}

