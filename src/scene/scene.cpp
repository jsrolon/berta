/*
 * scene.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: jsrolon
 */

#include "scene.h"
#include "ReflectiveMaterial.h"

/**
 * Builds the scene environment
 */
Scene::Scene() {
	film = new Film();
	Point pp = Point(30, -55, 150);
	Point p2 = Point(0, 0, 0);
	Vector v = Vector(0, 1, 0);
	cam = new PerspectiveCamera(film, this, pp, p2, v, 700);

	// Lights
	ambientLight = new AmbientLight();
	SpotLight* dLight = new SpotLight(Point(0, -40, -20), this, Point(0, 0, 0),
			1.0, 0.5); // uses radians
	lights.push_back(dLight);

	background_color = Color(0, 0, 0);

	// red sphere
	Shape * s = new Sphere();
	ReflectiveMaterial* mat = new ReflectiveMaterial(this, 0.6, 0.15, 0.2, 0.75,
			Color(1, 0, 0), Color(1, 1, 1), 250);
	Primitive redSphere = Primitive(s, mat);
	primitives.push_back(redSphere);

	// blue sphere
	Shape * s2 = new Sphere(Point(-10, -10, 26), 8);
	ReflectiveMaterial* mat3 = new ReflectiveMaterial(this, 0.65, 0.15, 0.2,
			0.75, Color(0, 0, 1), Color(1, 1, 1), 250);
	Primitive grrSphere = Primitive(s2, mat3);
	primitives.push_back(grrSphere);

	// green sphere
	Shape * s3 = new Sphere(Point(0, -24, 0), 4);
	ReflectiveMaterial* mat4 = new ReflectiveMaterial(this, 0.65, 0.15, 0.2,
			0.75, Color(0, 1, 0), Color(1, 1, 1), 250);
	Primitive omgSphere = Primitive(s3, mat4);
	primitives.push_back(omgSphere);

	// yellow sphere
	Shape * s4 = new Sphere(Point(28, 0, 0), 6);
	ReflectiveMaterial* mat5 = new ReflectiveMaterial(this, 0.65, 0.15, 0.2,
			0.75, Color(1, 1, 0), Color(1, 1, 1), 250);
	Primitive yellowSphere = Primitive(s4, mat5);
	primitives.push_back(yellowSphere);

	//purple sphere
	Shape * s5 = new Sphere(Point(35, -20, -15), 15);
	ReflectiveMaterial* mat6 = new ReflectiveMaterial(this, 0.65, 0.15, 0.2,
			0.75, Color(0.56, 0, 1), Color(1, 1, 1), 250);
	Primitive purpleSphere = Primitive(s5, mat6);
	primitives.push_back(purpleSphere);

	// create and add plane
	Shape* pl = new Plane();
	ReflectiveMaterial* mat2 = new ReflectiveMaterial(this, 0.65, 0.15, 0.2,
			0.75, Color(0.8, 0.4, 0), Color(1, 1, 1), 5);
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
