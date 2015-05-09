/*
 * Cone.cpp
 *
 *  Created on: May 9, 2015
 *      Author: jsrolon
 */

#include <Cone.h>

Cone::Cone(float theymin, float theymax) :
		ymin(theymin), ymax(theymax) {
}

bool Cone::intersect(const Ray& ray, float& tmin, Intersection& isct) const {
	float t;
	float a = ray.d.x * ray.d.x + ray.d.z * ray.d.z - ray.d.y * ray.d.y;
	float b = 2 * (ray.o.x * ray.d.x + ray.o.z * ray.d.z - ray.o.y * ray.d.y);
	float c = ray.o.x * ray.o.x + ray.o.z * ray.o.z - ray.o.y * ray.o.y;
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
			if (!(isct.point.y > ymin || isct.point.y < ymax)) {
				isct.normal = Normalize(
						Normal(2 * isct.point.x, -2 * isct.point.y,
								2 * isct.point.z));
				return true;
			}
		}
		t = (-b + e) / denom;
		if (t > EPSILON) {
			tmin = t;
			isct.point = ray.o + t * ray.d;
			if (isct.point.y > ymin || isct.point.y < ymax) {
				return false;
			}
			isct.normal = -Normalize(
					Normal(2 * isct.point.x, -2 * isct.point.y,
							2 * isct.point.z));
			return true;
		}
	}
	return false;
}

bool Cone::shadow_hit(const Ray& ray, float& tmin) const {
	Intersection isect;
	return intersect(ray, tmin, isect);
}

Cone::~Cone() {
	// TODO Auto-generated destructor stub
}

