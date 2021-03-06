/*
 * PerfectSpecularBRDF.cpp
 *
 *  Created on: Apr 18, 2015
 *      Author: jsrolon
 */

#include <PerfectSpecularBRDF.h>

PerfectSpecularBRDF::PerfectSpecularBRDF(float kspecular, Color colors) : cs(colors), ks(kspecular) {
	// TODO Auto-generated constructor stub

}

Color PerfectSpecularBRDF::sample_f(Intersection& isect, Vector& wi,
			const Vector& wo) {
	float ndotwo = Dot(isect.normal, wo);
	wi = -wo + (2.0 * Vector(isect.normal) * ndotwo);
	float denom = Dot(isect.normal,wi);
	Color omg = ks * cs;
	return (omg / denom);
}

PerfectSpecularBRDF::~PerfectSpecularBRDF() {
	// TODO Auto-generated destructor stub
}

