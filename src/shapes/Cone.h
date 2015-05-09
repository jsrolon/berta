/*
 * Cone.h
 *
 *  Created on: May 9, 2015
 *      Author: jsrolon
 */

#ifndef SHAPES_CONE_H_
#define SHAPES_CONE_H_

#include "berta.h"
#include "geometry.h"
#include "shape.h"
#include "intersection.h"

class Cone: public Shape {
protected:
	float ymin, ymax;
public:
	Cone(float ymin, float ymax);
	virtual bool intersect(const Ray& ray, float& tmin,
			Intersection& isct) const;

	virtual bool shadow_hit(const Ray& ray, float& tmin) const;
	virtual ~Cone();
};

#endif /* SHAPES_CONE_H_ */
