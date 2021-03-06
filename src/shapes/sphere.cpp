/*
 * sphere.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: jsrolon
 */

#include <sphere.h>

Sphere::Sphere() :
		center(*(new Point())), radius(20.0f) {
}

Sphere::Sphere(float x, float y, float z) :
		center(*(new Point(x, y, z))), radius(20.0f) {
}

Sphere::Sphere(Point pos, float rad) :
		center(pos), radius(rad) {
}

bool Sphere::shadow_hit(const Ray& ray, float& tmin) const {
	float t;
	Vector temp = ray.o - center;
	float a = Dot(ray.d, ray.d);
	float b = Dot(temp * 2.0f, ray.d);
	float c = Dot(temp, temp) - (radius * radius);
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

bool Sphere::intersect(const Ray& ray, float& tmin, Intersection& isct) const {
	float t;
	Vector temp = ray.o - center;
	float a = Dot(ray.d, ray.d);
	float b = Dot(temp * 2.0f, ray.d);
	float c = Dot(temp, temp) - (radius * radius);
	float discriminant = b * b - 4.0f * a * c;

	if (discriminant < 0.0f) {
		return false;
	} else {
		float e = sqrt(discriminant);
		float denom = 2.0f * a;
		t = (-b - e) / denom;
		if (t > EPSILON) {
			tmin = t;
			isct.normal = *(new Normal((temp + t * ray.d) / radius));
			isct.point = ray.o + t * ray.d;
			return true;
		}
		t = (-b + e) / denom;
		if (t > EPSILON) {
			tmin = t;
			isct.normal = *(new Normal((temp + t * ray.d) / radius));
			isct.point = ray.o + t * ray.d;
			return true;
		}
	}
	return false;
}

Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}

