/*
 * DiffuseMaterial.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: jsrolon
 */

#include <MatteMaterial.h>

/**
 * This is where the magic happens
 * @param isect
 * @return A color computed from adding each light source contribution multiplied by the BRDF
 */
Color MatteMaterial::shade(Intersection& isect) {
	// generate the exitant direction wo from the ray
	Vector wo = -isect.ray.d;
	// calculate the ambient lighting by multiplying the brdf's rho with the ambient light irradiance at that point
	Color L = ambient_brdf->rho(isect, wo) * scene->ambientLight->L(isect);

	// add each lights irradiance contribution multiplied by brdf
	for(auto &light : scene->lights) {
		Vector wi = light->direction(isect); // incident direction
		float ndotwi = Dot(isect.normal, wi);

		if(ndotwi > 0.0f) {
			L += diffuse_brdf->f(isect, wi, wo) * light->L(isect) * ndotwi; // these can be directional or point lights
		}
	}
	return L;
}

MatteMaterial::~MatteMaterial() {
	// TODO Auto-generated destructor stub
}

MatteMaterial::MatteMaterial(Scene* sc, float thekd, float theka, Color thecd) {
	diffuse_brdf = new Lambertian(thekd, thecd);
	ambient_brdf = new Lambertian(theka, thecd);
	scene = sc;
}