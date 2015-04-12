/*
 * PerspectiveCamera.h
 *
 *  Created on: Apr 10, 2015
 *      Author: jsrolon
 */

#ifndef CAMERAS_PERSPECTIVECAMERA_H_
#define CAMERAS_PERSPECTIVECAMERA_H_

#include <cameras/camera.h>

class PerspectiveCamera: public Camera {
public:
	/**
	 * TODO add again the member variables
	 * @param f
	 * @param scene
	 */
	PerspectiveCamera(Film* const f, Scene* const scene);

	virtual void render();

	virtual ~PerspectiveCamera();
};

#endif /* CAMERAS_PERSPECTIVECAMERA_H_ */
