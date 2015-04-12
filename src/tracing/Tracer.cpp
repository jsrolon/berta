/*
 * Tracer.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: jsrolon
 */

#include <Tracer.h>

Tracer::Tracer(Scene* const sc) :
		scene(sc) {

}

Color Tracer::trace(const Ray& ray) {
	Intersection isect;
	if(scene->intersect(ray, isect)) {
		return Color(1,0,0);
	} else return Color(0,0,0);
}

Tracer::~Tracer() {
	// TODO Auto-generated destructor stub
}
