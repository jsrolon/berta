/*
 * ThinLensCamera.cpp
 *
 *  Created on: May 7, 2015
 *      Author: jsrolon
 */

#include <ThinLensCamera.h>

ThinLensCamera::ThinLensCamera(Film* const f, Scene* const scene, Point& e,
		Point& lA, Vector& uup, float dis, float rad, float foc, float zo) {
	film = f;
	eye = e;
	lookAt = lA;
	up = uup;
	d = dis;
	radius = rad;
	focus = foc;
	zoom = zo;
	tracer = new Tracer(scene, 10);
	sampler = new RandomSampler();

	// Create the coordinate system
	w = eye - lookAt;
	w = Normalize(w);
	u = Cross(up, w);
	u = Normalize(u);
	v = Cross(w, u);
}

void ThinLensCamera::render() {
	int hres = film->hres;
	int vres = film->vres;

	// these are set here so that no space is allocated every iteration
	Point sp; // sample point (on unit square)
	Point pp; // pixel point
	Point dp; // disk point
	Point lp; // lens point

	Color raw_color;
	// for each one of the pixels
	for (int x = 0; x < hres; x++) {
		for (int y = 0; y < vres; y++) {
			// loop over samples per pixel
			for (int curSample = 0; curSample < sampler->numSamples;
					curSample++) {
				sp = sampler->sample();
				float xray = (x - (hres / 2) + sp.x);
				float yray = (y - (vres / 2) + sp.y);

				dp = sampler->sampleDisk();
				lp = dp * radius;

				Point rayorigin = eye + lp.x * u + lp.y * v;
				Vector direction = rayDirection(pp, lp);
				Ray ray = Ray(rayorigin, direction);

				// adds the color calculated by each sample
				raw_color += tracer->trace(ray);
			}
			// average color in every pixel
			raw_color = raw_color / sampler->numSamples;
			film->setPixelColor(x, y, raw_color); // set the color of the pixel on the film
		}
	}
}

Vector ThinLensCamera::rayDirection(Point pixelPoint, Point lensPoint) {
	Point p;
	p.x = pixelPoint.x * focus / d;
	p.y = pixelPoint.y * focus / d;

	Vector dir = (p.x - lensPoint.x) * u + (p.y - lensPoint.y) * v - focus * w;
	return Normalize(dir);
}

ThinLensCamera::~ThinLensCamera() {
	// TODO Auto-generated destructor stub
}

