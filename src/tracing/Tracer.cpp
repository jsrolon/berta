/*
 * Tracer.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: jsrolon
 */

#include <Tracer.h>

Tracer::Tracer(Scene* const sc, int dep) :
		scene(sc), max_depth(dep) {

}

Color Tracer::trace(Ray& ray) {
	if (ray.depth > max_depth) {
		return Color(0,0,0);
	} else {
		Intersection isect;
		if (scene->intersect(ray, isect)) {
			return isect.material->shade(isect);
		} else {
			ray.time = INFINITY; // khugevalue correction in suffern's book
			return scene->background_color;
		}
	}
}

Tracer::~Tracer() {
	// TODO Auto-generated destructor stub
}
