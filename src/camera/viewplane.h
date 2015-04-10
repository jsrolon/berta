/*
 * viewplane.h
 *
 *  Created on: Apr 9, 2015
 *      Author: jsrolon
 */

#ifndef CAMERA_VIEWPLANE_H_
#define CAMERA_VIEWPLANE_H_

#include "berta.h"

class ViewPlane {
public:
	int hres;
	int vres;
	float pxSize;

	float gamma;
	float invGamma;

	bool show_out_of_gamut;	// display red if RGBColor out of gamut

	ViewPlane();
	virtual ~ViewPlane();
};

#endif /* CAMERA_VIEWPLANE_H_ */
