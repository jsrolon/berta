/*
 * scene.h
 *
 *  Created on: Apr 2, 2015
 *      Author: jsrolon
 */

#ifndef SCENE_SCENE_H_
#define SCENE_SCENE_H_

#include "berta.h"
#include "viewplane.h"

class Scene {
public:
	Camera* cam;
	ViewPlane vp;

	RenderThread* paintArea; //connection to skeleton - wxRaytracer.h

	Scene();

	void build();
	void render();

	~Scene();
};

#endif /* SCENE_SCENE_H_ */
