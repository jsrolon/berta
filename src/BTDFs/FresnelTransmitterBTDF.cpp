/*
 * FresnelTransmitterBTDF.cpp
 *
 *  Created on: May 6, 2015
 *      Author: jsrolon
 */

#include <FresnelTransmitterBTDF.h>

FresnelTransmitterBTDF::FresnelTransmitterBTDF(float theetain, float theetaout,
		float thekt) :
		kt(thekt), etain(theetain), etaout(theetaout) {
}

// TODO changed eta by the division of the etas depending on ndotd
bool FresnelTransmitterBTDF::tir(Intersection& isect) {
	Vector wo(-isect.ray.d);
	Normal n(isect.normal);
	float ndotd = Dot(-n, isect.ray.d);
	float eta;

	if (ndotd < 0.0) {
		n = -n;
		eta = etaout / etain;
	} else {
		eta = etain / etain;
	}

	float costhetai = Dot(isect.normal, wo);

	if (costhetai < 0.0f) {
		eta = 1 / eta;
	}

	return (1.0 - (1.0 - costhetai * costhetai) / (eta * eta) < 0.0f);
}

// TODO changed eta by the division of the etas depending on ndotd
Color FresnelTransmitterBTDF::sample_f(const Intersection& isect,
		const Vector& wo, Vector& wt) {
	Normal n(isect.normal);
	float ndotd = Dot(-n, isect.ray.d);
	float eta;

	if (ndotd < 0.0) {
		n = -n;
		eta = etaout / etain;
	} else {
		eta = etain / etain;
	}
	float costhetai = Dot(n, wo);

	if (costhetai < 0.0f) {
		costhetai = -costhetai;
		n = -n;
		eta = 1.0 / eta;
	}

	float temp = 1.0 - (1.0 - costhetai * costhetai) / (eta * eta);
	float costheta2 = sqrt(temp);
	wt = -wo / eta - (costheta2 - costhetai / eta) * Vector(n);
	return (kt / (eta * eta) * Color(1, 1, 1) / fabs(Dot(isect.normal, wt)));
}

FresnelTransmitterBTDF::~FresnelTransmitterBTDF() {
	// TODO Auto-generated destructor stub
}

