/*
 * shape.h
 *
 *  Created on: Apr 2, 2015
 *      Author: jsrolon
 */

#ifndef SCENE_SHAPE_H_
#define SCENE_SHAPE_H_

#include "berta.h"

class Shape {
public:
	virtual bool intersect(const Ray& ray, float& tmin,
			Intersection& isct) const = 0;

	virtual ~Shape();
};

Shape::~Shape() {

}

#endif /* SCENE_SHAPE_H_ */
