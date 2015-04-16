/*
 * Lambertian.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: jsrolon
 */

#include <LambertianBRDF.h>

LambertianBRDF::LambertianBRDF(float & thekd, Color& thecd) :
		kd(thekd), cd(thecd) {

}

Color LambertianBRDF::f(Intersection& isect, const Vector& wi, const Vector& wo) {
	return kd * cd * INV_PI;
}

Color LambertianBRDF::rho(Intersection& isect, const Vector& wo) {
	return kd * cd;
}

LambertianBRDF::~LambertianBRDF() {
	// TODO Auto-generated destructor stub
}
