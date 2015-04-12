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
	sampler = new RandomSampler();

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
			Point sample;
			Color raw_color;
			// loop over samples per pixel
			for (int curSample = 0; curSample < sampler->numSamples;
					curSample++) {
				sample = sampler->sample();
				float xray = (x - (hres / 2) + sample.x);
				float yray = (y - (vres / 2) + sample.y);

				Point onFilm = Point(xray, yray, d);
				Vector direction = (xray * u) + (yray * v) - d * w;
				direction = Normalize(direction);
				Ray ray = Ray(eye, direction);

				raw_color += tracer->trace(ray);
			}
			raw_color = raw_color / sampler->numSamples;
			film->setPixelColor(x, y, raw_color);
		}
	}
}

PerspectiveCamera::~PerspectiveCamera() {
	// TODO Auto-generated destructor stub
}
