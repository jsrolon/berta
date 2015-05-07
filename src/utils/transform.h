/*
 * transform.h
 *
 *  Created on: Apr 2, 2015
 *      Author: jsrolon
 */

#ifndef UTILS_TRANSFORM_H_
#define UTILS_TRANSFORM_H_

#include "berta.h"

class Transform {
public:

	double m[4][4];								// elements

	Transform();									// default constructor

	Transform(const Transform& mat);						// copy constructor

	~Transform ();									// destructor

	Transform& 										// assignment operator
	operator=(const Transform& rhs);

	Transform 									// multiplication of two matrices
	operator*(const Transform& mat) const;

	Transform 											// divsion by a double
	operator/(const double d);
};

#endif /* UTILS_TRANSFORM_H_ */
