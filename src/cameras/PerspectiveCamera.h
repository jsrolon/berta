/*
 * PerspectiveCamera.h
 *
 *  Created on: Apr 10, 2015
 *      Author: jsrolon
 */

#ifndef CAMERAS_PERSPECTIVECAMERA_H_
#define CAMERAS_PERSPECTIVECAMERA_H_

#include <Camera.h>
#include "RandomSampler.h"

class PerspectiveCamera: public Camera {
public:
	PerspectiveCamera(Film* const f, Scene* const scene, Point& e, Point& lA,
			Vector& uup, float dis);

	virtual void render();

	virtual ~PerspectiveCamera();
protected:
	float d; // distance to the film
};

#endif /* CAMERAS_PERSPECTIVECAMERA_H_ */
