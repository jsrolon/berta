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

class Tracer {
public:
	virtual Color trace(const Ray&);
	virtual ~Tracer();
};

#endif /* TRACING_TRACER_H_ */
