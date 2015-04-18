/*
 * RandomSampler.cpp
 *
 *  Created on: Apr 12, 2015
 *      Author: jsrolon
 */

#include <RandomSampler.h>

RandomSampler::RandomSampler() {
	numSamples = 8;
}

RandomSampler::~RandomSampler() {
	// TODO Auto-generated destructor stub
}

/**
 * Randomly sample a 1x1 square
 * @return
 */
Point RandomSampler::sample() const {
	Point p;
	p.x = ((float) rand() / (RAND_MAX));
	p.y = ((float) rand() / (RAND_MAX));
	return p;
}
