/*
 * ThinLensCamera.h
 *
 *  Created on: May 7, 2015
 *      Author: jsrolon
 */

#ifndef CAMERAS_THINLENSCAMERA_H_
#define CAMERAS_THINLENSCAMERA_H_

#include <Camera.h>
#include "RandomSampler.h"

class ThinLensCamera: public Camera {
protected:
	float radius, d, focus, zoom;
public:

	ThinLensCamera(Film* const f, Scene* const scene, Point& e, Point& lA,
			Vector& uup, float dis, float rad, float foc, float zoom);

	Vector rayDirection(Point pixelPoint, Point lensPoint);

	virtual void render();

	virtual ~ThinLensCamera();
};

#endif /* CAMERAS_THINLENSCAMERA_H_ */
