/*
 * PointLight.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: jsrolon
 */

#include <PointLight.h>
#include "scene.h"

Vector PointLight::direction(Intersection& isect) {
	Vector v = p - isect.point;
	return Normalize(v);
}

Color PointLight::L(Intersection& isect) {
	return ls * cl;
}

PointLight::PointLight(Point pp, Scene* sc) :
		p(pp), attenuation(false), ls(3.0f), cl(Color(1, 1, 1)) {
	scene = sc;
	casts_shadows = true;

}

bool PointLight::in_shadow(Ray& ray, Intersection& intersection) {
	float distance = Distance(p, ray.o);
	float t;
	for(auto &primitive : scene->primitives) {
		if(primitive->shadow_hit(ray, t) && t < distance) {
			return true;
		}
	}
	return false;
}

PointLight::PointLight(Point pp, float l, Scene* sc) :
		ls(l), p(pp), attenuation(false) {
	scene = sc;
	casts_shadows = true;
}

PointLight::~PointLight() {
	// TODO Auto-generated destructor stub
}
