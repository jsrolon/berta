/*
 * DirectionalLight.h
 *
 *  Created on: Apr 18, 2015
 *      Author: jsrolon
 */

#ifndef LIGHTS_DIRECTIONALLIGHT_H_
#define LIGHTS_DIRECTIONALLIGHT_H_

#include <Light.h>

class DirectionalLight: public Light {
private:
	float ls; // light scaling
	Color cl; // light color
	Vector d; // direction
public:
	DirectionalLight(Vector dir, Scene* sc);

	virtual bool in_shadow(Ray& ray, Intersection& intersection);
	virtual Vector direction(Intersection& isect);
	virtual Color L(Intersection& isect);

	virtual ~DirectionalLight();
};

#endif /* LIGHTS_DIRECTIONALLIGHT_H_ */
