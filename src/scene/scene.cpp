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
	Point pp = Point(50, -20, 0);
	Point p2 = Point(0, 0, 0);
	Vector v = Vector(0, 1, 0);
	cam = new PerspectiveCamera(film, this, pp, p2, v, 150);

	// Lights
	ambientLight = new AmbientLight();
	PointLight* pLight = new PointLight(Point(30,-10,0), this);
	lights.push_back(pLight);

	background_color = Color(0,0,0);

	// create and add sphere
	Shape * s = new Sphere();
	PhongMaterial* mat = new PhongMaterial(this, 0.6, 0.15, 0.2, Color(1, 0, 0), 10);
	Primitive redSphere = Primitive(s, mat);
	primitives.push_back(redSphere);

	// create and add sphere
	Shape * s2 = new Sphere(-25, -25, 0);
	PhongMaterial* mat3 = new PhongMaterial(this, 0.65, 0.15, 0.4, Color(0, 0, 1), 10);
	Primitive grrSphere = Primitive(s2, mat3);
	primitives.push_back(grrSphere);

	// create and add plane
	Shape* pl = new Plane();
	MatteMaterial* mat2 = new MatteMaterial(this, 0.65, 0.15, Color(0.8, 0.4, 0));
	Primitive bluePlane = Primitive(pl, mat2);
	primitives.push_back(bluePlane);
}

void Scene::render() {
	cam->render();
}

bool Scene::intersect(const Ray& ray, Intersection& isect) {
	Intersection iTmp; // to return the intersection at the actual minimum t
	float tMin = INFINITY;
	for (auto &primitive : primitives) {
		float t;
		if (primitive.intersect(ray, t, iTmp) && t < tMin) {
			tMin = t;
			isect = iTmp;
		}
	}
	/**
	 * A lowest t has been found
	 */
	if (tMin != INFINITY) {
		isect.ray = ray;
		return true;
	} else {
		return false;
	}
}

Scene::~Scene() {
	delete film;
	delete cam;
}
