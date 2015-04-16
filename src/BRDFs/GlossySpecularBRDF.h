/*
 * GlossySpecularBRDF.h
 *
 *  Created on: Apr 16, 2015
 *      Author: jsrolon
 */

#ifndef BRDFS_GLOSSYSPECULARBRDF_H_
#define BRDFS_GLOSSYSPECULARBRDF_H_

#include <BRDF.h>

class GlossySpecularBRDF: public BRDF {
protected:
	float ks; // specular coeff
	float e; // exponent
	Color cs; // specular color
public:
	GlossySpecularBRDF(float ks, float e, Color cs);

	virtual Color f(Intersection& isect, const Vector& wi, const Vector& wo);
	virtual Color rho(Intersection& isect, const Vector& wo);

	virtual ~GlossySpecularBRDF();
};

#endif /* BRDFS_GLOSSYSPECULARBRDF_H_ */
