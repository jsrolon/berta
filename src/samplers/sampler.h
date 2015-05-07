/*
 * sampler.h
 *
 *  Created on: Apr 2, 2015
 *      Author: jsrolon
 */

#ifndef UTILS_SAMPLER_H_
#define UTILS_SAMPLER_H_

#include "berta.h"
#include "geometry.h"

class Sampler {
public:
	int numSamples;
	virtual Point sampleDisk() = 0;
	virtual Point sample() const = 0;
};

#endif /* UTILS_SAMPLER_H_ */
