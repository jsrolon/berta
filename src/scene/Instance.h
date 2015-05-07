/*
 * Instance.h
 *
 *  Created on: May 7, 2015
 *      Author: jsrolon
 */

#ifndef SCENE_INSTANCE_H_
#define SCENE_INSTANCE_H_

#include <primitive.h>

class Instance: public Primitive {
private:
	Primitive* primitive;
	Transform* invTransform;
public:
	Instance(Shape * const s, Material* const mat, Transform* t);

	bool intersect(const Ray& ray, float& tmin, Intersection& isct);

	bool shadow_hit(const Ray& ray, float& tmin);

	~Instance() {
		;
	}
};

#endif /* SCENE_INSTANCE_H_ */
