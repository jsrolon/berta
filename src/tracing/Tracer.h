/*
 * Tracer.h
 *
 *  Created on: Apr 10, 2015
 *      Author: jsrolon
 */

#ifndef TRACING_TRACER_H_
#define TRACING_TRACER_H_

#include "berta.h"
#include "color.h"
#include "geometry.h"
#include "scene.h"

class Tracer {
protected:
	Scene* scene;
	int max_depth;
public:
	Tracer(Scene* const sc, int dep);

	Color trace(Ray&);

	~Tracer();
};

#endif /* TRACING_TRACER_H_ */
