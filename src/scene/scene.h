/*
 * scene.h
 *
 *  Created on: Apr 2, 2015
 *      Author: jsrolon
 */

#ifndef SCENE_SCENE_H_
#define SCENE_SCENE_H_

#include <Camera.h>
#include <Light.h>
#include "berta.h"
#include "film.h"
#include "color.h"
#include "geometry.h"
#include "shape.h"
#include "primitive.h"
#include "intersection.h"
#include "color.h"
#include "instance.h"

/**
 * Abstract class implementations
 */
#include "sphere.h"
#include "SolidMaterial.h"
#include "plane.h"
#include "Triangle.h"
#include "Cylinder.h"
#include "MatteMaterial.h"
#include "AmbientLight.h"
#include "PointLight.h"
#include "PhongMaterial.h"
#include "DirectionalLight.h"
#include "SpotLight.h"

class Scene {
public:
	Camera* cam;

	Color background_color;

	/**
	 * Film is initialized when wxraytracer.cpp asks for its values
	 */
	Film* film;

	Light* ambientLight; // according to suffern

	vector<Primitive*> primitives;
	vector<Light*> lights;

	/**
	 * The scene constructor literally builds the scene
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
