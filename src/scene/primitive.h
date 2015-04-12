/*
 * primitive.h
 *
 *  Created on: Apr 2, 2015
 *      Author: jsrolon
 */

#ifndef SCENE_PRIMITIVE_H_
#define SCENE_PRIMITIVE_H_

#include "berta.h"
#include "shape.h"
#include "material.h"

class Primitive {
private:
	Shape* shape;
	Material* material;

public:
	Primitive(Shape * const s);

	bool intersect(const Ray& ray, float& tmin, Intersection& isct) {
		return shape->intersect(ray, tmin, isct);
	}

	~Primitive() {
		;
	}
};

#endif /* SCENE_PRIMITIVE_H_ */
