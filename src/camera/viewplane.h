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

	ViewPlane();
	virtual ~ViewPlane();
};

#endif /* CAMERA_VIEWPLANE_H_ */
