/*
 * GlossySpecularBRDF.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: jsrolon
 */

#include <GlossySpecularBRDF.h>

GlossySpecularBRDF::GlossySpecularBRDF(float kspecular, float exponent, Color cspec) :
		ks(kspecular), e(exponent), cs(cspec) {
	// TODO Auto-generated constructor stub
}

Color GlossySpecularBRDF::f(Intersection& isect, const Vector& wi,
		const Vector& wo) {
	Color L;
	float ndotwi = Dot(isect.normal, wi);
	Vector r(-wi + Vector(2.0 * isect.normal * ndotwi));
	float rdotwo = Dot(r, wo);

	if (rdotwo > 0.0f) {
		L = ks * cs * pow(rdotwo, e);
	}
	return L;
}

Color GlossySpecularBRDF::rho(Intersection& isect, const Vector& wo) {
	return Color(0,0,0);
}

GlossySpecularBRDF::~GlossySpecularBRDF() {
	// TODO Auto-generated destructor stub
}

