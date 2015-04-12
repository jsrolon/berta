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
	cam = new PerspectiveCamera(film, this);

	Shape * s = new Sphere();
	Primitive p = Primitive(s);
	primitives.push_back(p);
}

void Scene::render() {
	cam->render();
}

bool Scene::intersect(const Ray& ray, Intersection& isect) {
	float i = 0;
	for(auto &primitive : primitives) {
		if(primitive.intersect(ray,i,isect)) {
			return true;
		}
	}
	return false;
}

Scene::~Scene() {

}
