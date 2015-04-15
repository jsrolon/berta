/*
 * scene.h
 *
 *  Created on: Apr 2, 2015
 *      Author: jsrolon
 */

#ifndef SCENE_SCENE_H_
#define SCENE_SCENE_H_

#include "berta.h"
#include "film.h"
#include "color.h"
#include "geometry.h"
#include "shape.h"
#include "primitive.h"
#include "light.h"
#include "intersection.h"
#include "camera.h"

#include "sphere.h"
#include "PerspectiveCamera.h"
#include "SolidMaterial.h"
#include "plane.h"

class Scene {
public:
	Camera* cam;

	/**
	 * Film is initialized when wxraytracer.cpp asks for its values
	 */
	Film* film;

	Light* ambientLight; // according to suffern

	vector<Primitive> primitives;
	vector<Light*> lights;

	/**
	 * The scene constructor *constructs* the scene
	 */
	Scene();

	void render();
	bool intersect(const Ray& ray, Intersection& isect);

	/**
	 * The scene destructor *destructs* the scene
	 */
	~Scene();
};

#endif /* SCENE_SCENE_H_ */
