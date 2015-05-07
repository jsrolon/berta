/*
 * FresnelReflectorBRDF.cpp
 *
 *  Created on: May 6, 2015
 *      Author: jsrolon
 */

#include <FresnelReflectorBRDF.h>

FresnelReflectorBRDF::FresnelReflectorBRDF(float theetain, float theetaout, Color thecreflective) :
		etain(theetain), etaout(theetaout), cr(thecreflective) {
}

// TODO
Color FresnelReflectorBRDF::sample_f(Intersection& isect, Vector& wi,
		const Vector& wo) {
	float ndotwo = Dot(isect.normal, wo);
	wi = -wo + (2.0 * Vector(isect.normal) * ndotwo);
	float kr = fresnel(isect);
	return (kr * cr / Dot(isect.normal, wi));
}

float FresnelReflectorBRDF::fresnel(Intersection& isect) {
	Normal normal(isect.normal);
	float ndotd = Dot(-normal, isect.ray.d);
	float eta;

	if (ndotd < 0.0) {
		normal = -normal;
		eta = etaout / etain;
	} else {
		eta = etain / etain;
	}

	float costhetai = Dot(-normal, isect.ray.d);
	float temp = 1.0 - (1.0 - costhetai * costhetai) / (eta * eta);
	float costhetat = sqrt(temp); // TODO possible point of failure
	float rparallel = (eta * costhetai - costhetat)
			/ (eta * costhetai + costhetat);
	float rperpendicular = (costhetai - eta * costhetat)
			/ (costhetai + eta * costhetat);
	float kr = 0.5 * (rparallel * rparallel + rperpendicular * rperpendicular);

	return kr;
}

FresnelReflectorBRDF::~FresnelReflectorBRDF() {
}

