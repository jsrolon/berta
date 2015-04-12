/*
 * scene.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: jsrolon
 */

#include "scene.h"

/**
 * Builds the scene environment
 */
Scene::Scene() {
	film = new Film();
	Point pp = Point(50, -15, 0);
	Point p2 = Point(0, 0, 0);
	Vector v = Vector(0, 1, 0);
	cam = new PerspectiveCamera(film, this, pp, p2, v, 250);

	// create and add sphere
	Shape * s = new Sphere();
	SolidMaterial* mat = new SolidMaterial(Color(1, 0, 0));
	Primitive redSphere = Primitive(s, mat);
	primitives.push_back(redSphere);

	// create and add sphere
	Shape * s2 = new Sphere(0,0,35);
	SolidMaterial* mat3 = new SolidMaterial(Color(0, 1, 0));
	Primitive grrSphere = Primitive(s2, mat3);
	primitives.push_back(grrSphere);

	// create and add plane
	Shape* pl = new Plane();
	SolidMaterial* mat2 = new SolidMaterial(Color(0, 0, 1));
	Primitive bluePlane = Primitive(pl, mat2);
	primitives.push_back(bluePlane);
}

void Scene::render() {
	cam->render();
}

bool Scene::intersect(const Ray& ray, Intersection& isect) {
	Intersection iTmp;
	float tMin = INFINITY;
	for (auto &primitive : primitives) {
		float t;
		if (primitive.intersect(ray, t, iTmp)) {
			if (t < tMin) {
				tMin = t;
				isect = iTmp;
			}
		}
	}
	if (tMin != INFINITY) {
		return true;
	} else {
		return false;
	}
}

Scene::~Scene() {
	delete film;
	delete cam;
}
