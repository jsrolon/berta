/*
 * sphere.h
 *
 *  Created on: Apr 9, 2015
 *      Author: jsrolon
 */

#ifndef SHAPES_SPHERE_H_
#define SHAPES_SPHERE_H_

#include "berta.h"
#include "geometry.h"
#include "shape.h"
#include "intersection.h"

class Sphere : public Shape {
private:
	Point center;
	float radius;
public:
	Sphere();

	virtual bool intersect(const Ray& ray, float& tmin,
				Intersection& isct) const;

	virtual ~Sphere();
};

#endif /* SHAPES_SPHERE_H_ */
