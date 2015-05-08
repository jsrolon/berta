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
	Transform* invTransform;
	bool transformed;
public:
	Instance(Shape * const s, Material* const mat);

	bool intersect(const Ray& ray, float& tmin, Intersection& isct);

	bool shadow_hit(const Ray& ray, float& tmin);

	void scale(float a, float b, float c);

	void rotatex(float theta);
	void rotatey(float theta);
	void rotatez(float theta);

	~Instance() {
		;
	}
};

#endif /* SCENE_INSTANCE_H_ */
