/*
 * Instance.cpp
 *
 *  Created on: May 7, 2015
 *      Author: jsrolon
 */

#include <Instance.h>

Instance::Instance(Shape * const s, Material* const mat) :
		Primitive(s, mat) {
	invTransform = new Transform();
}

bool Instance::intersect(const Ray& ray, float& tmin, Intersection& isct) {
	Ray invRay(ray);
	invRay.o = *invTransform * invRay.o;
	invRay.d = *invTransform * invRay.d;
	if (Primitive::intersect(invRay, tmin, isct)) {
		isct.normal = *invTransform * isct.normal;
		isct.normal = Normalize(isct.normal);
		return true;
	}
	return false;
}

bool Instance::shadow_hit(const Ray& ray, float& tmin) {
	Ray invRay(ray);
	invRay.o = *invTransform * invRay.o;
	invRay.d = *invTransform * invRay.d;
	bool ans = Primitive::shadow_hit(invRay, tmin);
	return transformed ? !ans : ans;
}

void Instance::scale(float a, float b, float c) {
	Transform scale;
	scale.m[0][0] = 1 / a;
	scale.m[1][1] = 1 / b;
	scale.m[2][2] = 1 / c;

	*invTransform = *invTransform * scale;
	transformed = true;
}

void Instance::rotatex(float theta) {
	Transform rotate;
	rotate.m[1][1] = cos(theta);
	rotate.m[2][1] = sin(theta);
	rotate.m[1][2] = -sin(theta);
	rotate.m[2][2] = cos(theta);

	*invTransform = *invTransform * rotate;
	transformed = true;
}
void Instance::rotatey(float theta) {
	Transform rotate;
	rotate.m[0][0] = cos(theta);
	rotate.m[0][2] = sin(theta);
	rotate.m[2][0] = -sin(theta);
	rotate.m[2][2] = cos(theta);

	*invTransform = *invTransform * rotate;
	transformed = true;
}

void Instance::rotatez(float theta) {
	Transform rotate;
	rotate.m[0][0] = cos(theta);
	rotate.m[1][0] = sin(theta);
	rotate.m[0][1] = -sin(theta);
	rotate.m[1][1] = cos(theta);

	*invTransform = *invTransform * rotate;
	transformed = true;
}
