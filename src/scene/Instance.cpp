/*
 * Instance.cpp
 *
 *  Created on: May 7, 2015
 *      Author: jsrolon
 */

#include <Instance.h>

Instance::Instance(Shape * const s, Material* const mat, Transform* t) : Primitive(s, mat) {
	primitive = new Primitive(s, mat);
}

bool Instance::intersect(const Ray& ray, float& tmin, Intersection& isct) {
	Ray invRay(ray);
	invRay.o = *invTransform * invRay.o;
	invRay.d = *invTransform * invRay.d;
	if(primitive->intersect(invRay, tmin, isct)) {
		isct.normal = *invTransform * isct.normal;
		isct.normal = Normalize(isct.normal);
		return true;
	}
	return false;
}

bool Instance::shadow_hit(const Ray& ray, float& tmin) {
	Intersection is;
	return intersect(ray, tmin, is);
}
