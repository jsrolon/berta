/*
 * Triangle.cpp
 *
 *  Created on: May 9, 2015
 *      Author: jsrolon
 */

#include <Triangle.h>

Triangle::Triangle(Point p1, Point p2, Point p3) :
		v0(p1), v1(p2), v2(p3) {
	normal = Normal(Normalize(Cross((v1 - v0), (v2-v0))));
}

bool Triangle::intersect(const Ray& ray, float& tmin,
			Intersection& isct) const {
	float a = v0.x - v1.x, b = v0.x - v2.x, c = ray.d.x, d = v0.x - ray.o.x;
	float e = v0.y - v1.y, f = v0.y - v2.y, g = ray.d.y, h = v0.y - ray.o.y;
	float i = v0.z - v1.z, j = v0.z - v2.z, k = ray.d.z, l = v0.z - ray.o.z;

	float m = f * k - g * j, n = h * k - g * l, p = f * l - h * j;
	float q = g * i - e * k, s = e * j - f * i;

	float invDenom = 1.0 / (a * m + b * q + c*s);

	float e1 = d*m-b*n-c*p;
	double beta = e1 * invDenom;
	if(beta < 0.0f) {
		return false;
	}
	double r = e*l-h*i;
	double e2 = a*n+d*q+c*r;
	double gamma = e2*invDenom;
	if(gamma < 0.0f) {
		return false;
	}
	if(beta + gamma > 1.0) {
		return false;
	}
	double e3 = a*p-b*r+d*s;
	float t = e3*invDenom;
	if(t < EPSILON) {
		return false;
	}
	tmin = t;
	isct.normal = normal;
	isct.point = ray.o + t * ray.d;
	return true;
}

bool Triangle::shadow_hit(const Ray& ray, float& tmin) const {
	Intersection isect;
	return intersect(ray, tmin, isect);
}

Triangle::~Triangle() {
	// TODO Auto-generated destructor stub
}

