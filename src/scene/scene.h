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
#include "color.h"

class Scene {
public:
	Camera* cam;
	ViewPlane vp;

	RenderThread* film; //connection to skeleton - wxRaytracer.h

	Scene();

	void build();
	void render();
	void display_pixel(const int x, const int y, const Color& raw_color) const;

	Color max_to_one(const Color& c) const;
	Color clamp_to_color(const Color& raw_color) const;

	~Scene();
};

#endif /* SCENE_SCENE_H_ */
