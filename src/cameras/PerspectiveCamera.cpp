/*
 * PerspectiveCamera.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: jsrolon
 */

#include <cameras/PerspectiveCamera.h>

PerspectiveCamera::PerspectiveCamera(Film* const f, Scene* const scene) {
	film = f;
//	eye = e;
//	lookAt = lA;
//	up = u;
	tracer = new Tracer(scene);
}

void PerspectiveCamera::render() {
	int hres = film->hres;
	int vres = film->vres;
	for (int x = 0; x < hres; x++) {
		for (int y = 0; y < vres; y++) {
			float xray = (x - (hres / 2) + 0.5);
			float yray = (y - (vres / 2) + 0.5);
			float zray = 2;

			Point p = Point(xray, yray, zray);
			Vector v = Vector(0, 0, -1);
			Ray ray = Ray();
			ray.o = p;
			ray.d = v;

			Color raw_color = tracer->trace(ray);
			film->setPixelColor(x, y, raw_color);
		}
	}
}

PerspectiveCamera::~PerspectiveCamera() {
	// TODO Auto-generated destructor stub
}
