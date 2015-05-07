/*
 * FresnelReflectorBRDF.h
 *
 *  Created on: May 6, 2015
 *      Author: jsrolon
 */

#ifndef BRDFS_FRESNELREFLECTORBRDF_H_
#define BRDFS_FRESNELREFLECTORBRDF_H_

#include <BRDF.h>

class FresnelReflectorBRDF: public BRDF {
protected:
	float etain, etaout;
	Color cr;
public:
	FresnelReflectorBRDF(float theetain, float theetaout, Color thecreflective);

	virtual Color f(Intersection& isect, const Vector& wi, const Vector& wo) {
		return Color(0, 0, 0);
	}

	virtual Color sample_f(Intersection& isect, Vector& wi, const Vector& wo);
	float fresnel(Intersection& isect);

	virtual Color rho(Intersection& isect, const Vector& wo) {
		return Color(0, 0, 0);
	}

	virtual ~FresnelReflectorBRDF();
};

#endif /* BRDFS_FRESNELREFLECTORBRDF_H_ */
