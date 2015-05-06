/*
 * TransparentMaterial.cpp
 *
 *  Created on: May 5, 2015
 *      Author: jsrolon
 */

#include <TransparentMaterial.h>

TransparentMaterial::TransparentMaterial(Scene* sc, float kdiffuse,
		float kambient, float kspecular, float kreflective, float thekt,
		Color thecd, Color therc, float exponent, float theior) :
		PhongMaterial(sc, kdiffuse, kambient, kspecular, thecd, exponent) {
	reflective = new PerfectSpecularBRDF(kreflective, therc);
	specular_btdf = new PerfectTransmitterBTDF(theior, thekt);
}

Color TransparentMaterial::shade(Intersection& isect) {
	Color L = PhongMaterial::shade(isect);

	Vector wo = -isect.ray.d;
	Vector wi;
	Color fr = specular_btdf->sample_f(isect, wo, wi); // finds the value of wi
	Ray reflected(isect.point, wi, isect.ray, 0);

	if (specular_btdf->tir(isect)) {
		L += scene->cam->tracer->trace(reflected);
	} else {
		Vector wt;
		Color ft = specular_btdf->sample_f(isect, wo, wt);
		Ray transmitted(isect.point, wt, isect.ray, 0);
		L += fr * scene->cam->tracer->trace(reflected)
				* fabs(Dot(isect.normal, wi));
		L += ft * scene->cam->tracer->trace(reflected)
				* fabs(Dot(isect.normal, wt));
	}
	return L;
}

TransparentMaterial::~TransparentMaterial() {
	// TODO Auto-generated destructor stub
}

