/*
 * AmbientLight.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: jsrolon
 */

#include <AmbientLight.h>

Vector AmbientLight::direction(Intersection& isect) {
	return Vector();
}

Color AmbientLight::L(Intersection& isect) {
	return ls * cl;
}

AmbientLight::AmbientLight() : ls(1.0), cl(Color(1,1,1)) {

}

AmbientLight::AmbientLight(float l, Color c) : ls(l), cl(c) {
	// TODO Auto-generated constructor stub

}

AmbientLight::~AmbientLight() {
	// TODO Auto-generated destructor stub
}
