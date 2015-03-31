/*
 * shape.h
 *
 *  Created on: Mar 31, 2015
 *      Author: jsrolon
 */

#ifndef SHAPES_SHAPE_H_
#define SHAPES_SHAPE_H_

#include "berta.h"

class Shape {
public:
	virtual bool intersect(const Ray& ray, double& tmin,
			const Intersection& itsct) const = 0;
	virtual ~Shape();
};

#endif /* SHAPE_H_ */
