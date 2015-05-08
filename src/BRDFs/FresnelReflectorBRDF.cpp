/*
 * FresnelReflectorBRDF.cpp
 *
 *  Created on: May 6, 2015
 *      Author: jsrolon
 */

#include <FresnelReflectorBRDF.h>

FresnelReflectorBRDF::FresnelReflectorBRDF(float theetain, float theetaout,
		Color thecreflective) :
		etain(theetain), etaout(theetaout), cr(thecreflective) {
}

Color FresnelReflectorBRDF::sample_f(Intersection& isect, Vector& wr,
		const Vector& wo) {
	float ndotwo = Dot(isect.normal, wo);
	wr = -wo + Vector(2.0 * isect.normal * ndotwo);
	return (fresnel(isect) * Color(1,1,1) / fabs(Dot(isect.normal, wr)));
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
	float costhetat = sqrt(temp);
	float rparallel = (eta * costhetai - costhetat)
			/ (eta * costhetai + costhetat);
	float rperpendicular = (costhetai - eta * costhetat)
			/ (costhetai + eta * costhetat);
	float kr = 0.5 * (rparallel * rparallel + rperpendicular * rperpendicular);
	return kr;
}

FresnelReflectorBRDF::~FresnelReflectorBRDF() {
}

