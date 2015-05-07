/*
 * RandomSampler.h
 *
 *  Created on: Apr 12, 2015
 *      Author: jsrolon
 */

#ifndef SAMPLERS_RANDOMSAMPLER_H_
#define SAMPLERS_RANDOMSAMPLER_H_

#include <sampler.h>

class RandomSampler: public Sampler {
public:
	RandomSampler();
	virtual Point sample() const;
	virtual Point sampleDisk();
	virtual ~RandomSampler();
};

#endif /* SAMPLERS_RANDOMSAMPLER_H_ */
