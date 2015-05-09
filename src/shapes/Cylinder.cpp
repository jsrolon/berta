/*
 * Cylinder.cpp
 *
 *  Created on: May 9, 2015
 *      Author: jsrolon
 */

#include <Cylinder.h>

Cylinder::Cylinder(float radius, float theymin, float theymax) :
		r(radius), ymin(theymin), ymax(theymax) {
}

bool Cylinder::intersect(const Ray& ray, float& tmin,
		Intersection& isct) const {
	float t;
	float a = ray.d.x * ray.d.x + ray.d.z * ray.d.z;
	float b = 2 * (ray.o.x * ray.d.x + ray.o.z * ray.d.z);
	float c = ray.o.x * ray.o.x + ray.o.z * ray.o.z - r * r;
	float discriminant = b * b - 4.0f * a * c;

	if (discriminant < 0.0f) {
		return false;
	} else {
		float e = sqrt(discriminant);
		float denom = 2.0f * a;
		t = (-b - e) / denom;
		if (t > EPSILON) {
			tmin = t;
			isct.point = ray.o + t * ray.d;
			if (isct.point.y > ymin || isct.point.y < ymax) {
				return false;
			}
			isct.normal = Normalize(
					Normal(isct.point.x / r, 0, isct.point.z / r));
			return true;
		}
		t = (-b + e) / denom;
		if (t > EPSILON) {
			tmin = t;
			isct.point = ray.o + t * ray.d;
			if (isct.point.y > ymin || isct.point.y < ymax) {
				return false;
			}
			isct.normal = Normalize(
					Normal(isct.point.x / r, 0, isct.point.z / r));
			return true;
		}
	}
	return false;
}

bool Cylinder::shadow_hit(const Ray& ray, float& tmin) const {
	float t;
	float a = ray.d.x * ray.d.x + ray.d.z * ray.d.z;
	float b = 2 * (ray.o.x * ray.d.x + ray.o.z * ray.d.z);
	float c = ray.o.x * ray.o.x + ray.o.z * ray.o.z - r * r;
	float discriminant = b * b - 4.0f * a * c;

	if (discriminant < 0.0f) {
		return false;
	} else {
		float e = sqrt(discriminant);
		float denom = 2.0f * a;
		t = (-b - e) / denom;
		if (t > EPSILON) {
			tmin = t;
			return true;
		}
		t = (-b + e) / denom;
		if (t > EPSILON) {
			tmin = t;
			return true;
		}
	}
	return false;
}

Cylinder::~Cylinder() {
	// TODO Auto-generated destructor stub
}

