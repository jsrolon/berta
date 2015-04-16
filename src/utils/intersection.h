/*
 * intersection.h
 *
 *  Created on: Apr 2, 2015
 *      Author: jsrolon
 */

#ifndef UTILS_INTERSECTION_H_
#define UTILS_INTERSECTION_H_

#include <Material.h>
#include "berta.h"
#include "geometry.h"

class Intersection {
public:
	bool hit;
	Point point; // ALWAYS in world coordinates
	Normal normal; // at hit point, world coords
	Material* material;
	Ray ray; // ray that generated the intersection

	Intersection();

	~Intersection();
};

#endif /* UTILS_INTERSECTION_H_ */
