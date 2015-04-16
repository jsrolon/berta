/*
 * material.h
 *
 *  Created on: Apr 2, 2015
 *      Author: jsrolon
 */

#ifndef SCENE_MATERIAL_H_
#define SCENE_MATERIAL_H_

#include "berta.h"
#include "color.h"

class Material {
public:
	virtual Color shade(Intersection& isect) = 0;
	virtual ~Material() {};
};

#endif /* SCENE_MATERIAL_H_ */
