/*
 * DielectricMaterial.h
 *
 *  Created on: May 6, 2015
 *      Author: jsrolon
 */

#ifndef MATERIALS_DIELECTRICMATERIAL_H_
#define MATERIALS_DIELECTRICMATERIAL_H_

#include <PhongMaterial.h>
#include "FresnelReflectorBRDF.h"
#include "FresnelTransmitterBTDF.h"

class DielectricMaterial: public PhongMaterial {
protected:
	Color cfin, cfout;

	FresnelReflectorBRDF* fresnel_brdf;
	FresnelTransmitterBTDF* fresnel_btdf;
public:
	DielectricMaterial(Scene* sc, float kdiffuse, float kambient,
			float kspecular, float ktransmittive, Color thecdiffuse, Color thecreflective, float exponent, float theetain,
			float theetaout, Color cfin, Color cfout);

	virtual Color shade(Intersection& isect);

	virtual ~DielectricMaterial();
};

#endif /* MATERIALS_DIELECTRICMATERIAL_H_ */
