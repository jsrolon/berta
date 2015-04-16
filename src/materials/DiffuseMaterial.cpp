/*
 * DiffuseMaterial.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: jsrolon
 */

#include <DiffuseMaterial.h>

Color DiffuseMaterial::shade(Intersection& isect) {
	// find the appropriate brdf value
	for(auto &light : scene->lights) {
		// add each lights irradiance contribution multiplied by brdf?
	}
}

DiffuseMaterial::~DiffuseMaterial() {
	// TODO Auto-generated destructor stub
}

DiffuseMaterial::DiffuseMaterial(Scene* sc, float thekd, Color thecd) {
	brdf = new Lambertian(thekd, thecd);
	scene = sc;
}

