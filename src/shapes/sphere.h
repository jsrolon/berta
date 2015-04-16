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
	Sphere(float x, float y, float z);
	Sphere(Point pos, float rad);

	virtual bool intersect(const Ray& ray, float& tmin,
				Intersection& isct) const;

	virtual bool shadow_hit(const Ray& ray, float& tmin) const;

	virtual ~Sphere();
};

#endif /* SHAPES_SPHERE_H_ */
