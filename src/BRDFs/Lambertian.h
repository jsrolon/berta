/*
 * Lambertian.h
 *
 *  Created on: Apr 15, 2015
 *      Author: jsrolon
 */

#ifndef BRDFS_LAMBERTIAN_H_
#define BRDFS_LAMBERTIAN_H_

#include <BRDFs/BRDF.h>

class Lambertian: public BRDF {
public:
	virtual Color f(Intersection& isect, const Vector& wi, const Vector& wo);
	virtual Color rho(Intersection& isect, const Vector& wo);

	virtual ~Lambertian();
};

#endif /* BRDFS_LAMBERTIAN_H_ */
