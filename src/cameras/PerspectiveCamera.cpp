/*
 * PerspectiveCamera.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: jsrolon
 */

#include <cameras/PerspectiveCamera.h>

PerspectiveCamera::PerspectiveCamera(Film* const f, Scene* const scene,
		Point& e, Point& lA, Vector& uup, float dis) {
	film = f;
	eye = e;
	lookAt = lA;
	up = uup;
	d = dis;
	tracer = new Tracer(scene);

	// Create the coordinate system
	w = eye - lookAt;
	w = Normalize(w);
	u = Cross(up, w);
	u = Normalize(u);
	v = Cross(w, u);
}

void PerspectiveCamera::render() {
	int hres = film->hres;
	int vres = film->vres;
	for (int x = 0; x < hres; x++) {
		for (int y = 0; y < vres; y++) {
			float xray = (x - (hres / 2) + 0.5);
			float yray = (y - (vres / 2) + 0.5);

			Point onFilm = Point(xray, yray, d);
			Vector direction = (xray * u) + (yray * v) - d * w;
			direction = Normalize(direction);
			Ray ray = Ray(eye, direction);

			Color raw_color = tracer->trace(ray);
			film->setPixelColor(x, y, raw_color);
		}
	}
}

PerspectiveCamera::~PerspectiveCamera() {
	// TODO Auto-generated destructor stub
}
