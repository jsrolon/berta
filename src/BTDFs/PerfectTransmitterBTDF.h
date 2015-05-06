/*
 * PerfectTransmitterBTDF.h
 *
 *  Created on: May 6, 2015
 *      Author: jsrolon
 */

#ifndef BTDFS_PERFECTTRANSMITTERBTDF_H_
#define BTDFS_PERFECTTRANSMITTERBTDF_H_

#include <BTDF.h>

class PerfectTransmitterBTDF: public BTDF {
protected:
	float kt, ior;
public:
	PerfectTransmitterBTDF(float theior, float thekt);

	virtual bool tir(Intersection& isect);
	virtual Color sample_f(const Intersection& isect, const Vector& wo,
			Vector& wt);

	virtual ~PerfectTransmitterBTDF();
};

#endif /* BTDFS_PERFECTTRANSMITTERBTDF_H_ */
