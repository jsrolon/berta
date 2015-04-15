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
		// do the necessary shading
		return isect.material->shade();
	} else return Color(0.8,1,1);
}

Tracer::~Tracer() {
	// TODO Auto-generated destructor stub
}
