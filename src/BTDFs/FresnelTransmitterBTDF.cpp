/*
 * FresnelTransmitterBTDF.cpp
 *
 *  Created on: May 6, 2015
 *      Author: jsrolon
 */

#include <FresnelTransmitterBTDF.h>

FresnelTransmitterBTDF::FresnelTransmitterBTDF(float theetain, float theetaout) :
		etain(theetain), etaout(theetaout) {
}

bool FresnelTransmitterBTDF::tir(Intersection& isect) {
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
	return (1.0 - (1.0 - costhetai * costhetai) / (eta * eta) < 0.0f);
}

// TODO changed eta by the division of the etas depending on ndotd
Color FresnelTransmitterBTDF::sample_f(const Intersection& isect,
		const Vector& wo, Vector& wt) {
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
	float kt = 1 - (0.5 * (rparallel * rparallel + rperpendicular * rperpendicular));
	wt = -wo / eta - (costhetat - costhetai / eta) * Vector(normal);
	return (kt / (eta * eta) * Color(1, 1, 1) / fabs(Dot(isect.normal, wt)));
}

FresnelTransmitterBTDF::~FresnelTransmitterBTDF() {
}

