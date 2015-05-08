/*
 * DielectricMaterial.cpp
 *
 *  Created on: May 6, 2015
 *      Author: jsrolon
 */

#include <DielectricMaterial.h>

DielectricMaterial::DielectricMaterial(Scene* sc, float kdiffuse,
		float kambient, float kspecular, float ktransmittive, Color thecdiffuse, Color thecreflective, float exponent,
		float theetain, float theetaout, Color thecfin, Color thecfout) :
		PhongMaterial(sc, kdiffuse, kambient, kspecular, thecdiffuse, exponent), cfin(
				thecfin), cfout(thecfout) {
	scene = sc;
	fresnel_brdf = new FresnelReflectorBRDF(theetain, theetaout, thecreflective);
	fresnel_btdf = new FresnelTransmitterBTDF(theetain, theetaout);
}

Color DielectricMaterial::shade(Intersection& isect) {
	Color L(PhongMaterial::shade(isect));

	Vector wo(-isect.ray.d);
	Vector wi;
	Color fr = fresnel_brdf->sample_f(isect, wi, wo); //computing wi
	Ray reflected(isect.point, wi, isect.ray, 0); // child ray
	Color Lr, Lt;
	float ndotwi = Dot(isect.normal, wi);
	if (fresnel_btdf->tir(isect)) {
		if (ndotwi < 0.0f) {
			Lr = scene->cam->tracer->trace(reflected);
			L += cfin.powc(reflected.time) * Lr;
		} else {
			Lr = scene->cam->tracer->trace(reflected);
			L += cfout.powc(reflected.time) * Lr;
		}
	} else { // there's no tir
		Vector wt;
		Color ft = fresnel_btdf->sample_f(isect, wo, wt); // compute wt
		Ray transmitted(isect.point, wt, isect.ray, 0); // also child ray
		float ndotwt = Dot(isect.normal, wt);

		if (ndotwi < 0.0) {
			//reflected ray is inside
			Lr = fr * scene->cam->tracer->trace(reflected) * fabs(ndotwi);
			L += cfin.powc(reflected.time) * Lr;

			//transmitted is outside
			Lt = ft * scene->cam->tracer->trace(transmitted) * fabs(ndotwt);
			L += cfout.powc(transmitted.time) * Lt;
		} else {
			// reflected and transmitted switch locations
			Lr = fr * scene->cam->tracer->trace(reflected) * fabs(ndotwi);
			L += cfout.powc(reflected.time) * Lr;

			Color omg = scene->cam->tracer->trace(transmitted);
			Lt = ft * omg * fabs(ndotwt);
			L += cfin.powc(transmitted.time) * Lt;
		}
	}
	return L;
}

DielectricMaterial::~DielectricMaterial() {
}

