/*
 * PhongMaterial.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: jsrolon
 */

#include <PhongMaterial.h>

Color PhongMaterial::shade(Intersection& isect) {
	// generate the exitant direction wo from the ray
	Vector wo = -isect.ray.d;
	// calculate the ambient lighting by multiplying the brdf's rho with the ambient light irradiance at that point
	Color L = ambient->rho(isect, wo) * scene->ambientLight->L(isect);

	// add each lights irradiance contribution multiplied by brdf
	for (auto &light : scene->lights) {
		Vector wi = light->direction(isect); // incident direction
		float ndotwi = Dot(isect.normal, wi);

		if (ndotwi > 0.0f) {
			bool in_shadow = false;
			if (light->casts_shadows) {
				Ray shadowRay(isect.point, wi);
				in_shadow = light->in_shadow(shadowRay, isect);
			}
			if (!in_shadow) {
				L += (diffuse->f(isect, wi, wo) + specular->f(isect, wi, wo))
						* light->L(isect) * ndotwi; // combination of diffuse lighting and specular
			}
		}
	}
	return L;
}

PhongMaterial::PhongMaterial(Scene* sc, float kdiffuse, float kambient,
		float kspecular, Color thecd, float exponent) {
	scene = sc;
	diffuse = new LambertianBRDF(kdiffuse, thecd);
	ambient = new LambertianBRDF(kambient, thecd);
	specular = new GlossySpecularBRDF(kspecular, exponent, Color(1,1,1));
}

PhongMaterial::~PhongMaterial() {
	// TODO Auto-generated destructor stub
}

