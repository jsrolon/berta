/*
 * PointLight.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: jsrolon
 */

#include <PointLight.h>

Vector PointLight::direction(Intersection& isect) {
	Vector v = p - isect.point;
	return Normalize(v);
}

Color PointLight::L(Intersection& isect) {
	return ls * cl;
}

PointLight::PointLight(Point pp) :
		p(pp), attenuation(false), ls(2.0f), cl(Color(1, 1, 1)) {

}

PointLight::PointLight(Point pp, float l) :
		ls(l), p(pp), attenuation(false) {
}

PointLight::~PointLight() {
	// TODO Auto-generated destructor stub
}
