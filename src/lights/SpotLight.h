/*
 * SpotLight.h
 *
 *  Created on: Apr 18, 2015
 *      Author: jsrolon
 */

#ifndef LIGHTS_SPOTLIGHT_H_
#define LIGHTS_SPOTLIGHT_H_

#include <Light.h>

class SpotLight: public Light {
private:
	float ls; // light scaling
	Color cl; // light color
	Point p; // location!

	float cosWidth, cosFallOff;
	Vector dir;
public:
	SpotLight(Point pos, Scene* sc, Point lA, float wAngle, float fallAngle);

	virtual bool in_shadow(Ray& ray, Intersection& intersection);
	virtual Vector direction(Intersection& isect);
	virtual Color L(Intersection& isect);

	virtual ~SpotLight();
};

#endif /* LIGHTS_SPOTLIGHT_H_ */
