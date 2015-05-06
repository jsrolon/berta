/*
 * BTDF.h
 *
 *  Created on: May 5, 2015
 *      Author: jsrolon
 */

#ifndef BTDFS_BTDF_H_
#define BTDFS_BTDF_H_

#include "berta.h"
#include "geometry.h"
#include "intersection.h"

class BTDF {
public:
	virtual bool tir(Intersection& isect) = 0;
	virtual Color sample_f(const Intersection& isect, const Vector& wo, Vector& wt) = 0;
	virtual ~BTDF();
};

#endif /* BTDFS_BTDF_H_ */
