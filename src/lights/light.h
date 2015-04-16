/*
 * light.h
 *
 *  Created on: Apr 10, 2015
 *      Author: jsrolon
 */

#ifndef LIGHTS_LIGHT_H_
#define LIGHTS_LIGHT_H_

#include "berta.h"
#include "intersection.h"
#include "color.h"

class Light {
public:
	/**
	 *
	 * @param isect
	 * @return incident direction at point isect.p
	 */
	virtual Vector direction(Intersection& isect) = 0;

	/**
	 * Incident irradiance at point isect.p
	 * @param isect
	 * @return
	 */
	virtual Color L(Intersection& isect) = 0;
	virtual ~Light() {};
};

#endif /* LIGHTS_LIGHT_H_ */
