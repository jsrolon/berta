/*
 * camera.h
 *
 *  Created on: Apr 9, 2015
 *      Author: jsrolon
 */

#ifndef CAMERA_CAMERA_H_
#define CAMERA_CAMERA_H_

#include "berta.h"
#include "geometry.h"
#include "viewplane.h"

class Camera {
public:
//	Point& eye;
//	Point& lookAt;
//	Vector& up;
//	ViewPlane& viewPlane;

	Camera();
	Camera(const Point& e, const Point& lA, const Vector& u,
			const ViewPlane& vp);

	virtual Ray& primaryRay(const Point& pos) const = 0;

	virtual ~Camera();
};

#endif /* CAMERA_CAMERA_H_ */
