/*
 * PerfectTransmitterBTDF.cpp
 *
 *  Created on: May 6, 2015
 *      Author: jsrolon
 */

#include <PerfectTransmitterBTDF.h>

PerfectTransmitterBTDF::PerfectTransmitterBTDF(float theior, float thekt) :
		ior(theior), kt(thekt) {
	// TODO Auto-generated constructor stub
}

bool PerfectTransmitterBTDF::tir(Intersection& isect) {
	Vector wo(-isect.ray.d);
	float costhetai = Dot(isect.normal, wo);
	float eta = ior;

	if (costhetai < 0.0f) {
		eta = 1 / eta;
	}

	return (1.0 - (1.0 - costhetai * costhetai) / (eta * eta) < 0.0f);
}

Color PerfectTransmitterBTDF::sample_f(const Intersection& isect,
		const Vector& wo, Vector& wt) {
	Normal n(isect.normal);
	float costhetai = Dot(n, wo);
	float eta = ior;

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

PerfectTransmitterBTDF::~PerfectTransmitterBTDF() {
	// TODO Auto-generated destructor stub
}

