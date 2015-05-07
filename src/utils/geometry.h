/*
 pbrt source code Copyright(c) 1998-2012 Matt Pharr and Greg Humphreys.

 This file is part of pbrt.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are
 met:

 - Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.

 - Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */

#ifndef UTILS_GEOMETRY_H_
#define UTILS_GEOMETRY_H_

#include "berta.h"
#include "transform.h"

/**
 * Vector class def
 */
class Vector {
public:
	float x, y, z;

	Vector() {
		x = y = z = 0.f;
	}
	Vector(float xx, float yy, float zz) :
			x(xx), y(yy), z(zz) {
	}

	explicit Vector(const Point& p);

	Vector(const Vector &v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}

	Vector &operator=(const Vector &v) {
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	Vector operator+(const Vector &v) const {
		return Vector(x + v.x, y + v.y, z + v.z);
	}

	Vector& operator+=(const Vector &v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	Vector operator-(const Vector &v) const {
		return Vector(x - v.x, y - v.y, z - v.z);
	}

	Vector& operator-=(const Vector &v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}
	Vector operator*(float f) const {
		return Vector(f * x, f * y, f * z);
	}

	Vector &operator*=(float f) {
		x *= f;
		y *= f;
		z *= f;
		return *this;
	}
	Vector operator/(float f) const {
		float inv = 1.f / f;
		return Vector(x * inv, y * inv, z * inv);
	}

	Vector &operator/=(float f) {
		float inv = 1.f / f;
		x *= inv;
		y *= inv;
		z *= inv;
		return *this;
	}
	Vector operator-() const {
		return Vector(-x, -y, -z);
	}
	float operator[](int i) const {
		return (&x)[i];
	}

	float &operator[](int i) {
		return (&x)[i];
	}
	float LengthSquared() const {
		return x * x + y * y + z * z;
	}
	float Length() const {
		return sqrtf(LengthSquared());
	}

	explicit Vector(const Normal& n);

	bool operator==(const Vector &v) const {
		return x == v.x && y == v.y && z == v.z;
	}
	bool operator!=(const Vector &v) const {
		return x != v.x || y != v.y || z != v.z;
	}

	~Vector();
};

/**
 * Point class def
 */
class Point {
public:
	float x, y, z;

	Point() {
		x = y = z = 0.f;
	}
	Point(float xx, float yy, float zz) :
			x(xx), y(yy), z(zz) {
	}

	Point(const Point &p) {
		x = p.x;
		y = p.y;
		z = p.z;
	}

	Point &operator=(const Point &p) {
		x = p.x;
		y = p.y;
		z = p.z;
		return *this;
	}

	Point operator+(const Vector &v) const {
		return Point(x + v.x, y + v.y, z + v.z);
	}

	Point &operator+=(const Vector &v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	Vector operator-(const Point &p) const {
		return Vector(x - p.x, y - p.y, z - p.z);
	}

	Point operator-(const Vector &v) const {
		return Point(x - v.x, y - v.y, z - v.z);
	}

	Point &operator-=(const Vector &v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}
	Point &operator+=(const Point &p) {
		x += p.x;
		y += p.y;
		z += p.z;
		return *this;
	}
	Point operator+(const Point &p) const {
		return Point(x + p.x, y + p.y, z + p.z);
	}
	Point operator*(float f) const {
		return Point(f * x, f * y, f * z);
	}
	Point &operator*=(float f) {
		x *= f;
		y *= f;
		z *= f;
		return *this;
	}
	Point operator/(float f) const {
		float inv = 1.f / f;
		return Point(inv * x, inv * y, inv * z);
	}
	Point &operator/=(float f) {
		float inv = 1.f / f;
		x *= inv;
		y *= inv;
		z *= inv;
		return *this;
	}
	float operator[](int i) const {
		return (&x)[i];
	}

	float &operator[](int i) {
		return (&x)[i];
	}

	bool operator==(const Point &p) const {
		return x == p.x && y == p.y && z == p.z;
	}
	bool operator!=(const Point &p) const {
		return x != p.x || y != p.y || z != p.z;
	}

	~Point();
};

/**
 * Normal class def and inline operations
 */
class Normal {
public:
	float x, y, z;

	Normal() {
		x = y = z = 0.f;
	}
	Normal(float xx, float yy, float zz) :
			x(xx), y(yy), z(zz) {
	}
	Normal operator-() const {
		return Normal(-x, -y, -z);
	}
	Normal operator+(const Normal &n) const {
		return Normal(x + n.x, y + n.y, z + n.z);
	}

	Normal& operator+=(const Normal &n) {
		x += n.x;
		y += n.y;
		z += n.z;
		return *this;
	}
	Normal operator-(const Normal &n) const {
		return Normal(x - n.x, y - n.y, z - n.z);
	}

	Normal& operator-=(const Normal &n) {
		x -= n.x;
		y -= n.y;
		z -= n.z;
		return *this;
	}
	Normal operator*(float f) const {
		return Normal(f * x, f * y, f * z);
	}

	Normal &operator*=(float f) {
		x *= f;
		y *= f;
		z *= f;
		return *this;
	}
	Normal operator/(float f) const {
		float inv = 1.f / f;
		return Normal(x * inv, y * inv, z * inv);
	}

	Normal &operator/=(float f) {
		float inv = 1.f / f;
		x *= inv;
		y *= inv;
		z *= inv;
		return *this;
	}
	float LengthSquared() const {
		return x * x + y * y + z * z;
	}
	float Length() const {
		return sqrtf(LengthSquared());
	}

	Normal(const Normal &n) {
		x = n.x;
		y = n.y;
		z = n.z;
	}

	Normal &operator=(const Normal &n) {
		x = n.x;
		y = n.y;
		z = n.z;
		return *this;
	}
	explicit Normal(const Vector &v) :
			x(v.x), y(v.y), z(v.z) {
	}
	float operator[](int i) const {
		return (&x)[i];
	}

	float &operator[](int i) {
		return (&x)[i];
	}

	bool operator==(const Normal &n) const {
		return x == n.x && y == n.y && z == n.z;
	}
	bool operator!=(const Normal &n) const {
		return x != n.x || y != n.y || z != n.z;
	}

	~Normal();
};

/**
 * Ray class def
 */
class Ray {
public:
	Point o;
	Vector d;
	mutable float mint, maxt;
	float time;
	int depth;

	Ray() :
			mint(0.f), maxt(INFINITY), time(0.f), depth(0) {
	}
	Ray(const Point &origin, const Vector& direction) :
			o(origin), d(direction), mint(0.f), maxt(INFINITY), time(0.f), depth(
					0) {

	}
	Ray(const Point &origin, const Vector &direction, float start, float end =
	INFINITY, float t = 0.f, int d = 0) :
			o(origin), d(direction), mint(start), maxt(end), time(t), depth(d) {
	}
	Ray(const Point &origin, const Vector &direction, const Ray &parent,
			float start, float end = INFINITY) :
			o(origin), d(direction), mint(start), maxt(end), time(parent.time), depth(
					parent.depth + 1) {
	}
	Point operator()(float t) const {
		return o + d * t;
	}

	~Ray();
};

/**
 * BBox class def and inline operations
 */
class BBox {
public:
	Point pMin, pMax;

	BBox() {
		pMin = Point( INFINITY, INFINITY, INFINITY);
		pMax = Point(-INFINITY, -INFINITY, -INFINITY);
	}
	BBox(const Point &p) :
			pMin(p), pMax(p) {
	}
	BBox(const Point &p1, const Point &p2) {
		pMin = Point(min(p1.x, p2.x), min(p1.y, p2.y), min(p1.z, p2.z));
		pMax = Point(max(p1.x, p2.x), max(p1.y, p2.y), max(p1.z, p2.z));
	}
	friend BBox Union(const BBox &b, const Point &p);
	friend BBox Union(const BBox &b, const BBox &b2);
	bool Overlaps(const BBox &b) const {
		bool x = (pMax.x >= b.pMin.x) && (pMin.x <= b.pMax.x);
		bool y = (pMax.y >= b.pMin.y) && (pMin.y <= b.pMax.y);
		bool z = (pMax.z >= b.pMin.z) && (pMin.z <= b.pMax.z);
		return (x && y && z);
	}
	bool Inside(const Point &pt) const {
		return (pt.x >= pMin.x && pt.x <= pMax.x && pt.y >= pMin.y
				&& pt.y <= pMax.y && pt.z >= pMin.z && pt.z <= pMax.z);
	}
	void Expand(float delta) {
		pMin -= Vector(delta, delta, delta);
		pMax += Vector(delta, delta, delta);
	}
	float SurfaceArea() const {
		Vector d = pMax - pMin;
		return 2.f * (d.x * d.y + d.x * d.z + d.y * d.z);
	}
	float Volume() const {
		Vector d = pMax - pMin;
		return d.x * d.y * d.z;
	}
	int MaximumExtent() const {
		Vector diag = pMax - pMin;
		if (diag.x > diag.y && diag.x > diag.z)
			return 0;
		else if (diag.y > diag.z)
			return 1;
		else
			return 2;
	}

	const Point &operator[](int i) const;
	Point &operator[](int i);
	Point Lerp(float tx, float ty, float tz) const {
		return Point(::Lerp(tx, pMin.x, pMax.x), ::Lerp(ty, pMin.y, pMax.y),
				::Lerp(tz, pMin.z, pMax.z));
	}
	Vector Offset(const Point &p) const {
		return Vector((p.x - pMin.x) / (pMax.x - pMin.x),
				(p.y - pMin.y) / (pMax.y - pMin.y),
				(p.z - pMin.z) / (pMax.z - pMin.z));
	}
	void BoundingSphere(Point *c, float *rad) const;
	bool IntersectP(const Ray &ray, float *hitt0 = NULL,
			float *hitt1 = NULL) const;

	bool operator==(const BBox &b) const {
		return b.pMin == pMin && b.pMax == pMax;
	}
	bool operator!=(const BBox &b) const {
		return b.pMin != pMin || b.pMax != pMax;
	}

	~BBox();
};

/**
 * Inline functions
 */
inline Vector::Vector(const Point &p) :
		x(p.x), y(p.y), z(p.z) {
}

inline Vector operator*(float f, const Vector &v) {
	return v * f;
}
inline float Dot(const Vector &v1, const Vector &v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline float Dot(const Normal &v1, const Vector &v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline float AbsDot(const Vector &v1, const Vector &v2) {
	return fabsf(Dot(v1, v2));
}

inline Vector Cross(const Vector &v1, const Vector &v2) {
	double v1x = v1.x, v1y = v1.y, v1z = v1.z;
	double v2x = v2.x, v2y = v2.y, v2z = v2.z;
	return Vector((v1y * v2z) - (v1z * v2y), (v1z * v2x) - (v1x * v2z),
			(v1x * v2y) - (v1y * v2x));
}

inline Vector Cross(const Vector &v1, const Normal &v2) {
	double v1x = v1.x, v1y = v1.y, v1z = v1.z;
	double v2x = v2.x, v2y = v2.y, v2z = v2.z;
	return Vector((v1y * v2z) - (v1z * v2y), (v1z * v2x) - (v1x * v2z),
			(v1x * v2y) - (v1y * v2x));
}

inline Vector Cross(const Normal &v1, const Vector &v2) {
	double v1x = v1.x, v1y = v1.y, v1z = v1.z;
	double v2x = v2.x, v2y = v2.y, v2z = v2.z;
	return Vector((v1y * v2z) - (v1z * v2y), (v1z * v2x) - (v1x * v2z),
			(v1x * v2y) - (v1y * v2x));
}

inline Vector Normalize(const Vector &v) {
	return v / v.Length();
}
inline void CoordinateSystem(const Vector &v1, Vector *v2, Vector *v3) {
	if (fabsf(v1.x) > fabsf(v1.y)) {
		float invLen = 1.f / sqrtf(v1.x * v1.x + v1.z * v1.z);
		*v2 = Vector(-v1.z * invLen, 0.f, v1.x * invLen);
	} else {
		float invLen = 1.f / sqrtf(v1.y * v1.y + v1.z * v1.z);
		*v2 = Vector(0.f, v1.z * invLen, -v1.y * invLen);
	}
	*v3 = Cross(v1, *v2);
}

inline float Distance(const Point &p1, const Point &p2) {
	return (p1 - p2).Length();
}

inline float DistanceSquared(const Point &p1, const Point &p2) {
	return (p1 - p2).LengthSquared();
}

inline Point operator*(float f, const Point &p) {
	return p * f;
}

inline Normal operator*(float f, const Normal &n) {
	return Normal(f * n.x, f * n.y, f * n.z);
}

inline Normal Normalize(const Normal &n) {
	return n / n.Length();
}

inline Vector::Vector(const Normal &n) :
		x(n.x), y(n.y), z(n.z) {
}

inline float Dot(const Vector &v1, const Normal &n2) {
	return v1.x * n2.x + v1.y * n2.y + v1.z * n2.z;
}

inline float Dot(const Normal &n1, const Normal &n2) {
	return n1.x * n2.x + n1.y * n2.y + n1.z * n2.z;
}

inline float AbsDot(const Normal &n1, const Vector &v2) {
	return fabsf(n1.x * v2.x + n1.y * v2.y + n1.z * v2.z);
}

inline float AbsDot(const Vector &v1, const Normal &n2) {
	return fabsf(v1.x * n2.x + v1.y * n2.y + v1.z * n2.z);
}

inline float AbsDot(const Normal &n1, const Normal &n2) {
	return fabsf(n1.x * n2.x + n1.y * n2.y + n1.z * n2.z);
}

inline Normal Faceforward(const Normal &n, const Vector &v) {
	return (Dot(n, v) < 0.f) ? -n : n;
}

inline Normal Faceforward(const Normal &n, const Normal &n2) {
	return (Dot(n, n2) < 0.f) ? -n : n;
}

inline Vector Faceforward(const Vector &v, const Vector &v2) {
	return (Dot(v, v2) < 0.f) ? -v : v;
}

inline Vector Faceforward(const Vector &v, const Normal &n2) {
	return (Dot(v, n2) < 0.f) ? -v : v;
}

inline const Point &BBox::operator[](int i) const {
	return (&pMin)[i];
}

inline Point &BBox::operator[](int i) {
	return (&pMin)[i];
}

inline Vector SphericalDirection(float sintheta, float costheta, float phi) {
	return Vector(sintheta * cosf(phi), sintheta * sinf(phi), costheta);
}

inline Vector SphericalDirection(float sintheta, float costheta, float phi,
		const Vector &x, const Vector &y, const Vector &z) {
	return sintheta * cosf(phi) * x + sintheta * sinf(phi) * y + costheta * z;
}

inline float SphericalTheta(const Vector &v) {
	return acosf(Clamp(v.z, -1.f, 1.f));
}

inline float SphericalPhi(const Vector &v) {
	float p = atan2f(v.y, v.x);
	return (p < 0.f) ? p + 2.f * M_PI : p;
}

inline Point operator*(const Transform& mat, const Point& p) {
	return (Point(
			mat.m[0][0] * p.x + mat.m[0][1] * p.y + mat.m[0][2] * p.z
					+ mat.m[0][3],
			mat.m[1][0] * p.x + mat.m[1][1] * p.y + mat.m[1][2] * p.z
					+ mat.m[1][3],
			mat.m[2][0] * p.x + mat.m[2][1] * p.y + mat.m[2][2] * p.z
					+ mat.m[2][3]));
}

inline Vector operator*(const Transform& mat, const Vector& v) {
	return (Vector(mat.m[0][0] * v.x + mat.m[0][1] * v.y + mat.m[0][2] * v.z,
			mat.m[1][0] * v.x + mat.m[1][1] * v.y + mat.m[1][2] * v.z,
			mat.m[2][0] * v.x + mat.m[2][1] * v.y + mat.m[2][2] * v.z));
}

inline Normal operator*(const Transform& mat, const Normal& n) {
	return (Normal(mat.m[0][0] * n.x + mat.m[1][0] * n.y + mat.m[2][0] * n.z,
			mat.m[0][1] * n.x + mat.m[1][1] * n.y + mat.m[2][1] * n.z,
			mat.m[0][2] * n.x + mat.m[1][2] * n.y + mat.m[2][2] * n.z));
}

#endif /* UTILS_GEOMETRY_H_ */
