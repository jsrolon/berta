/*
 * SolidMaterial.h
 *
 *  Created on: Apr 12, 2015
 *      Author: jsrolon
 */

#ifndef MATERIALS_SOLIDMATERIAL_H_
#define MATERIALS_SOLIDMATERIAL_H_

#include <material.h>
#include "berta.h"
#include "color.h"

class SolidMaterial: public Material {
public:
	Color color;

	SolidMaterial(const Color& col);

	virtual ~SolidMaterial();
};

#endif /* MATERIALS_SOLIDMATERIAL_H_ */
