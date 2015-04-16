/*
 * DiffuseMaterial.h
 *
 *  Created on: Apr 15, 2015
 *      Author: jsrolon
 */

#ifndef MATERIALS_DIFFUSEMATERIAL_H_
#define MATERIALS_DIFFUSEMATERIAL_H_

#include <material.h>
#include "BRDF.h"
#include "Lambertian.h"
#include "scene.h"

class DiffuseMaterial: public Material {
protected:
	BRDF* brdf;
	Scene* scene;
public:
	virtual Color shade(Intersection& isect);
	virtual ~DiffuseMaterial();
	DiffuseMaterial(Scene* sc, float thekd, Color thecd);
};

#endif /* MATERIALS_DIFFUSEMATERIAL_H_ */
