/*
 * ReflectiveMaterial.cpp
 *
 *  Created on: Apr 18, 2015
 *      Author: jsrolon
 */

#include <ReflectiveMaterial.h>

ReflectiveMaterial::ReflectiveMaterial(Scene* sc, float kdiffuse,
		float kambient, float kspecular, float kreflective, Color thecd, Color therc,
		float exponent) : PhongMaterial(sc, kdiffuse, kambient, kspecular, thecd, exponent) {
	reflective = new PerfectSpecularBRDF(kreflective, therc);
}

Color ReflectiveMaterial::shade(Intersection& isect) {
	Color L(PhongMaterial::shade(isect)); // direct illum
	Vector wo = -isect.ray.d;
	Vector wi;
	Color fr = reflective->sample_f(isect, wi, wo);
	Ray reflected(isect.point, wi, isect.ray, 0);
	L+= fr * Dot(isect.normal, wi) * scene->cam->tracer->trace(reflected);
	return L;
}

ReflectiveMaterial::~ReflectiveMaterial() {
	// TODO Auto-generated destructor stub
}

