/*
 * PerfectSpecularBRDF.h
 *
 *  Created on: Apr 18, 2015
 *      Author: jsrolon
 */

#ifndef BRDFS_PERFECTSPECULARBRDF_H_
#define BRDFS_PERFECTSPECULARBRDF_H_

#include <BRDF.h>

class PerfectSpecularBRDF: public BRDF {
private:
	float ks; // specular coeff
	Color cs; // specular color
public:
	PerfectSpecularBRDF(float ks, Color cs);

	virtual Color f(Intersection& isect, const Vector& wi,
			const Vector& wo) {
		return Color(0,0,0);
	}

	/**
	 * Same as f, but is used to retrieve the value of wi (unknown)
	 * @param isect
	 * @param wi
	 * @param wo
	 * @return
	 */
	virtual Color sample_f(Intersection& isect, Vector& wi,
			const Vector& wo);
	virtual Color rho(Intersection& isect, const Vector& wo) {
		return Color(0,0,0);
	}

	virtual ~PerfectSpecularBRDF();
};

#endif /* BRDFS_PERFECTSPECULARBRDF_H_ */
