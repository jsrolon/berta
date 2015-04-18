/*
 * BRDF.h
 *
 *  Created on: Apr 15, 2015
 *      Author: jsrolon
 */

#ifndef BRDFS_BRDF_H_
#define BRDFS_BRDF_H_

#include "berta.h"
#include "geometry.h"
#include "intersection.h"

class BRDF {
public:
	/**
	 * Will be multiplied by the irradiance of every light
	 * @param isect Contains the point at which the BRDF will be calculated
	 * @param wi Incident direction (from where the light comes)
	 * @param wo Reflecting direction (towards the camera)
	 * @return The reflected radiance in direction wo at point isect.p
	 */
	virtual Color f(Intersection& isect, const Vector& wi, const Vector& wo) = 0;

	/**
	 * Same as f, but is used to retrieve the value of wi (unknown)
	 * @param isect
	 * @param wi
	 * @param wo
	 * @return
	 */
	virtual Color sample_f(Intersection& isect, Vector& wi, const Vector& wo) {};
	virtual Color rho(Intersection& isect, const Vector& wo) = 0;

	virtual ~BRDF();
};

#endif /* BRDFS_BRDF_H_ */
