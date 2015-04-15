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

class DiffuseMaterial: public Material {
protected:
	BRDF* brdf;
public:
	virtual ~DiffuseMaterial();
	DiffuseMaterial();
};

#endif /* MATERIALS_DIFFUSEMATERIAL_H_ */
