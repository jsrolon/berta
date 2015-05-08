/*
 * SpotLight.cpp
 *
 *  Created on: Apr 18, 2015
 *      Author: jsrolon
 */

#include <SpotLight.h>
#include "scene.h"

SpotLight::SpotLight(Point pos, Scene* sc, Point lA, float wAngle,
		float fallAngle) :
		ls(5.0), cl(Color(1, 1, 1)) {
	p = pos;
	scene = sc;
	cosWidth = cos(wAngle);
	cosFallOff = cos(fallAngle);
	dir = Normalize(lA - pos);
	casts_shadows = true;
}

bool SpotLight::in_shadow(Ray& ray, Intersection& intersection) {
	float distance = Distance(p, ray.o);
	float t;
	for (auto &primitive : scene->primitives) {
		if (primitive->shadow_hit(ray, t) && t < distance) {
			return true;
		}
	}
	return false;
}

Vector SpotLight::direction(Intersection& isect) {
	Vector v = p - isect.point;
	return Normalize(v);
}

Color SpotLight::L(Intersection& isect) {
	Vector between = Normalize(isect.point - p);
	float costheta = Dot(between, dir); // both are normalized
	float falloff;
	if (costheta < cosWidth)
		falloff = 0;
	else if (costheta > cosFallOff)
		falloff = 1;
	else {
		float delta = (costheta - cosWidth)
				/ (cosFallOff - cosWidth);
		falloff = delta * delta * delta * delta;
	}
	return ls * cl * falloff;
}

SpotLight::~SpotLight() {
	// TODO Auto-generated destructor stub
}

