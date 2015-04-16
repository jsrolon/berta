/*
 * plane.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: jsrolon
 */

#include "plane.h"

Plane::Plane() :
		point(*(new Point())), normal(*(new Normal(0, -1, 0))) {
}

Plane::Plane(const Point& p, const Normal& n) :
		point(p), normal(n) {
}

bool Plane::shadow_hit(const Ray& ray, float& tmin) const {
	float num = Dot((point - ray.o), normal);
		float denom = Dot(ray.d, normal);
		float t = num / denom;

		if (t > EPSILON) {
			tmin=t;
			return true;
		} else
			return false;
}

bool Plane::intersect(const Ray& ray, float& tmin,
		Intersection& isct) const {
	float num = Dot((point - ray.o), normal);
	float denom = Dot(ray.d, normal);
	float t = num / denom;

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
