/*
 * ReflectiveMaterial.h
 *
 *  Created on: Apr 18, 2015
 *      Author: jsrolon
 */

#ifndef MATERIALS_REFLECTIVEMATERIAL_H_
#define MATERIALS_REFLECTIVEMATERIAL_H_

#include "PhongMaterial.h"
#include "PerfectSpecularBRDF.h"

class ReflectiveMaterial : public PhongMaterial {
protected:
	BRDF* reflective;
public:
	ReflectiveMaterial(Scene* sc, float kdiffuse, float kambient, float kspecular, float kreflective,
			Color thecd, Color therc, float exponent);
	Color shade(Intersection& isect);
	virtual ~ReflectiveMaterial();
};

#endif /* MATERIALS_REFLECTIVEMATERIAL_H_ */
