/*
 * primitive.cpp
 *
 *  Created on: Apr 12, 2015
 *      Author: jsrolon
 */

#include "primitive.h"

bool Primitive::intersect(const Ray& ray, float& tmin, Intersection& isct) {
	if (shape->intersect(ray, tmin, isct)) {
		isct.material = material;
		return true;
	}
	return false;
}

bool Primitive::shadow_hit(const Ray& ray, float& tmin) {
	if (shape->shadow_hit(ray, tmin)) {
		return true;
	}
	return false;
}

Primitive::Primitive(Shape* const s, Material* const mat) {
	shape = s;
	material = mat;
}
