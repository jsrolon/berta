/*
 * plane.h
 *
 *  Created on: Apr 9, 2015
 *      Author: jsrolon
 */

#ifndef SHAPES_PLANE_H_
#define SHAPES_PLANE_H_

#include "berta.h"
#include "shape.h"
#include "geometry.h"
#include "intersection.h"

class Plane: public Shape {
private:
	Point point;
	Normal normal;
public:
	/**
	 * Default plane is the same as xz plane
	 */
	Plane();
	Plane(const Point& p, const Normal& n);

	virtual bool intersect(const Ray& ray, float& tmin,
			Intersection& isct) const;

	virtual bool shadow_hit(const Ray& ray, float& tmin) const;

	virtual ~Plane();
};

#endif /* SHAPES_PLANE_H_ */
