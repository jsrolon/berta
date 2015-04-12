/*
 * camera.h
 *
 *  Created on: Apr 9, 2015
 *      Author: jsrolon
 */

#ifndef CAMERAS_CAMERA_H_
#define CAMERAS_CAMERA_H_

#include "berta.h"
#include "geometry.h"
#include "Film.h"
#include "Tracer.h"

/**
 * Camera interface
 */
class Camera {
public:
	virtual void render() = 0;
	virtual ~Camera() {};
protected:
	Tracer* tracer;
	Film* film;
	Sampler* sampler;

	Point eye, lookAt;
	Vector up;

	Vector u, v, w; // coordinate system
};

#endif /* CAMERAS_CAMERA_H_ */
