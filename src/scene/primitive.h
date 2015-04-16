/*
 * primitive.h
 *
 *  Created on: Apr 2, 2015
 *      Author: jsrolon
 */

#ifndef SCENE_PRIMITIVE_H_
#define SCENE_PRIMITIVE_H_

#include <Material.h>
#include "berta.h"
#include "shape.h"
#include "intersection.h"

class Primitive {
private:
	Shape* shape;
	Material* material;

public:
	Primitive(Shape * const s, Material* const mat);

	bool intersect(const Ray& ray, float& tmin, Intersection& isct);

	bool shadow_hit(const Ray& ray, float& tmin);

	~Primitive() {
		;
	}
};

#endif /* SCENE_PRIMITIVE_H_ */
