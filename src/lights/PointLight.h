/*
 * PointLight.h
 *
 *  Created on: Apr 16, 2015
 *      Author: jsrolon
 */

#ifndef LIGHTS_POINTLIGHT_H_
#define LIGHTS_POINTLIGHT_H_

#include <Light.h>

class PointLight: public Light {
private:
	float ls; // light scaling
	Color cl; // light color
	Point p; // location!
	bool attenuation; // distance attenuation
public:
	PointLight(Point pp);
	PointLight(Point pp, float l);

	virtual Vector direction(Intersection& isect);
	virtual Color L(Intersection& isect);

	virtual ~PointLight();
};

#endif /* LIGHTS_POINTLIGHT_H_ */
