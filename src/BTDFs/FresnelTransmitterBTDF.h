/*
 * FresnelTransmitterBTDF.h
 *
 *  Created on: May 6, 2015
 *      Author: jsrolon
 */

#ifndef BTDFS_FRESNELTRANSMITTERBTDF_H_
#define BTDFS_FRESNELTRANSMITTERBTDF_H_

#include <BTDF.h>

class FresnelTransmitterBTDF: public BTDF {
protected:
	float etain, etaout, kt;
public:
	FresnelTransmitterBTDF(float theetain, float theetaout, float thekt);

	virtual bool tir(Intersection& isect);
	virtual Color sample_f(const Intersection& isect, const Vector& wo,
			Vector& wt);

	virtual ~FresnelTransmitterBTDF();
};

#endif /* BTDFS_FRESNELTRANSMITTERBTDF_H_ */
