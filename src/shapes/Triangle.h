/*
 * Triangle.h
 *
 *  Created on: May 9, 2015
 *      Author: jsrolon
 */

#ifndef SHAPES_TRIANGLE_H_
#define SHAPES_TRIANGLE_H_

#include "berta.h"
#include "geometry.h"
#include "shape.h"
#include "intersection.h"

class Triangle: public Shape {
protected:
	Point v0, v1, v2;
	Normal normal;
public:
	Triangle(Point p1, Point p2, Point p3);
	virtual bool intersect(const Ray& ray, float& tmin,
			Intersection& isct) const;
	virtual bool shadow_hit(const Ray& ray, float& tmin) const;
	virtual ~Triangle();
};

#endif /* SHAPES_TRIANGLE_H_ */
