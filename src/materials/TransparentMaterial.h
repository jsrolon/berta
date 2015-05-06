/*
 * TransparentMaterial.h
 *
 *  Created on: May 5, 2015
 *      Author: jsrolon
 */

#ifndef MATERIALS_TRANSPARENTMATERIAL_H_
#define MATERIALS_TRANSPARENTMATERIAL_H_

#include <PhongMaterial.h>
#include "BRDF.h"
#include "scene.h"
#include "BTDF.h"
#include "PerfectSpecularBRDF.h"
#include "PerfectTransmitterBTDF.h"

class TransparentMaterial: public PhongMaterial {
	BRDF* reflective;
	BTDF* specular_btdf;
public:
	TransparentMaterial(Scene* sc, float kdiffuse, float kambient, float kspecular, float kreflective, float ktransmittive,
			Color thecd, Color therc, float exponent, float ior);
	Color shade(Intersection& isect);
	virtual ~TransparentMaterial();
};

#endif /* MATERIALS_TRANSPARENTMATERIAL_H_ */
