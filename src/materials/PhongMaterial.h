/*
 * PhongMaterial.h
 *
 *  Created on: Apr 16, 2015
 *      Author: jsrolon
 */

#ifndef MATERIALS_PHONGMATERIAL_H_
#define MATERIALS_PHONGMATERIAL_H_

#include <Material.h>
#include "BRDF.h"
#include "GlossySpecularBRDF.h"
#include "LambertianBRDF.h"
#include "scene.h"

class PhongMaterial: public Material {
private:
	BRDF* ambient;
	BRDF* diffuse;
	BRDF* specular;
	Scene* scene;
public:
	PhongMaterial(Scene* sc, float kdiffuse, float kambient, float kspecular,
			Color thecd, float exponent);
	Color shade(Intersection& isect);

	virtual ~PhongMaterial();
};

#endif /* MATERIALS_PHONGMATERIAL_H_ */
