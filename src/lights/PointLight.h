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
	PointLight(Point pp, Scene* sc);
	PointLight(Point pp, float l, Scene* sc);

	virtual bool in_shadow(Ray& ray, Intersection& intersection);
	virtual Vector direction(Intersection& isect);
	virtual Color L(Intersection& isect);

	virtual ~PointLight();
};

#endif /* LIGHTS_POINTLIGHT_H_ */
