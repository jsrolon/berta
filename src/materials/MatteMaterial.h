/*
 * DiffuseMaterial.h
 *
 *  Created on: Apr 15, 2015
 *      Author: jsrolon
 */

#ifndef MATERIALS_MATTEMATERIAL_H_
#define MATERIALS_MATTEMATERIAL_H_

#include <LambertianBRDF.h>
#include <Material.h>
#include "BRDF.h"
#include "scene.h"

class MatteMaterial: public Material {
protected:
	BRDF* diffuse_brdf;
	BRDF* ambient_brdf;
	Scene* scene;
public:
	virtual Color shade(Intersection& isect);
	virtual ~MatteMaterial();
	MatteMaterial(Scene* sc, float thekd, float theka, Color thecd);
};

#endif /* MATERIALS_MATTEMATERIAL_H_ */
