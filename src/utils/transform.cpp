/*
 * transform.cpp
 *
 *  Created on: May 7, 2015
 *      Author: jsrolon
 */

#include "transform.h"

Transform::Transform(void) {
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++) {
			if (x == y)
				m[x][y] = 1.0;
			else
				m[x][y] = 0.0;
		}
}

Transform::Transform(const Transform& mat) {
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			m[x][y] = mat.m[x][y];
}

Transform::~Transform() {
}

Transform&
Transform::operator=(const Transform& rhs) {
	if (this == &rhs)
		return (*this);

	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			m[x][y] = rhs.m[x][y];

	return (*this);
}

Transform Transform::operator*(const Transform& mat) const {
	Transform product;

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++) {
			double sum = 0.0;

			for (int j = 0; j < 4; j++)
				sum += m[x][j] * mat.m[j][y];

			product.m[x][y] = sum;
		}

	return (product);
}

Transform Transform::operator/(const double d) {
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			m[x][y] = m[x][y] / d;

	return (*this);
}
