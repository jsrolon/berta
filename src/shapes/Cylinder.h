/*
 * Cylinder.h
 *
 *  Created on: May 9, 2015
 *      Author: jsrolon
 */

#ifndef SHAPES_CYLINDER_H_
#define SHAPES_CYLINDER_H_

#include "berta.h"
#include "geometry.h"
#include "shape.h"
#include "intersection.h"

class Cylinder: public Shape {
protected:
	float r, ymin, ymax;
public:
	Cylinder(float radius, float ymin, float ymax);
	virtual bool intersect(const Ray& ray, float& tmin,
			Intersection& isct) const;

	virtual bool shadow_hit(const Ray& ray, float& tmin) const;
	virtual ~Cylinder();
};

#endif /* SHAPES_CYLINDER_H_ */
