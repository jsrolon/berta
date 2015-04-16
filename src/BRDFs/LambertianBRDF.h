/*
 * Lambertian.h
 *
 *  Created on: Apr 15, 2015
 *      Author: jsrolon
 */

#ifndef BRDFS_LAMBERTIANBRDF_H_
#define BRDFS_LAMBERTIANBRDF_H_

#include <BRDFs/BRDF.h>

class LambertianBRDF: public BRDF {
protected:
	float kd; // diffuse reflection coefficient
	Color cd; // diffuse color
public:
	LambertianBRDF(float& thekd, Color& thecd);

	virtual Color f(Intersection& isect, const Vector& wi, const Vector& wo);
	virtual Color rho(Intersection& isect, const Vector& wo);

	virtual ~LambertianBRDF();
};

#endif /* BRDFS_LAMBERTIANBRDF_H_ */
