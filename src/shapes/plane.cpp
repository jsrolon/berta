/*
 * plane.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: jsrolon
 */

#include "plane.h"

Plane::Plane() :
		point(*(new Point())), normal(*(new Normal(0, 1, 0))) {
}

Plane::Plane(const Point& p, const Normal& n) :
		point(p), normal(n) {
}

bool Plane::intersect(const Ray& ray, float& tmin,
		Intersection& isct) const {
	float t = Dot((point - ray.o), normal) / Dot(ray.d, normal);

	if (t > EPSILON) {
		tmin = t;
		isct.normal = normal;
		isct.point = ray.o + t * ray.d;
		return true;
	} else
		return false;
}

Plane::~Plane() {
	// TODO Auto-generated destructor stub
}
