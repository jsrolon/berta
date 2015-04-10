/*
 * PerspectiveCamera.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: jsrolon
 */

#include <cameras/PerspectiveCamera.h>

PerspectiveCamera::PerspectiveCamera() {

}

void PerspectiveCamera::render() {
	for (int x = 0; x < film->hres; x++) {
		for (int y = 0; y < film->vres; y++) {
			float xray = (x - (film->hres / 2) + 0.5);
			float yray = (y - (film->vres / 2) + 0.5);
			float zray = 2;
			Point p = Point(xray, yray, zray);
			Vector v = Vector(0, 0, -1);
			Ray ray = Ray();
			ray.o = p;
			ray.d = v;

			Color c = tracer->trace(ray);
		}
	}
}

PerspectiveCamera::~PerspectiveCamera() {
	// TODO Auto-generated destructor stub
}
