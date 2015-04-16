/*
 * AmbientLight.h
 *
 *  Created on: Apr 16, 2015
 *      Author: jsrolon
 */

#ifndef LIGHTS_AMBIENTLIGHT_H_
#define LIGHTS_AMBIENTLIGHT_H_

#include <Light.h>

class AmbientLight: public Light {
private:
	/**
	 * Light scaling factor
	 */
	float ls;

	/**
	 * Color of the light
	 */
	Color cl;
public:
	AmbientLight();
	AmbientLight(float l, Color c);

	virtual Vector direction(Intersection& isect);
	virtual Color L(Intersection& isect);

	virtual ~AmbientLight();
};

#endif /* LIGHTS_AMBIENTLIGHT_H_ */
