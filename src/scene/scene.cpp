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
	Point pp = Point(12, 22, 50);
	Point p2 = Point(0, 0, 0);
	Vector v = Vector(0, 1, 0);
	cam = new PerspectiveCamera(film, this, pp, p2, v, 100);

	// create and add sphere
	Shape * s = new Sphere();
	SolidMaterial* mat = new SolidMaterial(Color(1, 0, 0));
	Primitive redSphere = Primitive(s, mat);
	primitives.push_back(redSphere);
}

void Scene::render() {
	cam->render();
}

bool Scene::intersect(const Ray& ray, Intersection& isect) {
	float tMin = INFINITY;
	for (auto &primitive : primitives) {
		float t;
		if (primitive.intersect(ray, t, isect)) {
			if (t <= tMin) {
				tMin = t;
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
