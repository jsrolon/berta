/*
 * DirectionalLight.cpp
 *
 *  Created on: Apr 18, 2015
 *      Author: jsrolon
 */

#include <DirectionalLight.h>
#include "scene.h"

Vector DirectionalLight::direction(Intersection& isect) {
	return d;
}

Color DirectionalLight::L(Intersection& isect) {
	return ls * cl;
}

bool DirectionalLight::in_shadow(Ray& ray, Intersection& intersection) {
	float t;
	for (auto &primitive : scene->primitives) {
		if (primitive.shadow_hit(ray, t)) {
			return true;
		}
	}
	return false;
}

DirectionalLight::DirectionalLight(Vector dir, Scene* sc) :
		ls(1.0f), cl(Color(1, 1, 1)) {
	d = dir;
	scene = sc;
	casts_shadows = true;
}

DirectionalLight::~DirectionalLight() {
	// TODO Auto-generated destructor stub
}

