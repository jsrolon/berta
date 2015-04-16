/*
 * Lambertian.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: jsrolon
 */

#include <LambertianBRDF.h>

Lambertian::Lambertian(float & thekd, Color& thecd) :
		kd(thekd), cd(thecd) {

}

Color Lambertian::f(Intersection& isect, const Vector& wi, const Vector& wo) {
	return kd * cd * INV_PI;
}

Color Lambertian::rho(Intersection& isect, const Vector& wo) {
	return kd * cd;
}

Lambertian::~Lambertian() {
	// TODO Auto-generated destructor stub
}
