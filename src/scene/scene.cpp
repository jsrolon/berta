/*
 * scene.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: jsrolon
 */

#include "scene.h"
#include "wxraytracer.h"

Scene::Scene() {

}

void Scene::build() {

}

void Scene::render() {
	for (int x = 0; x < vp.hres; x++) {
		for (int y = 0; y < vp.vres; y++) {
			film->setPixel(x, y, x, x, x);
		}
	}
}

void Scene::display_pixel(const int x, const int y,
		const Color& raw_color) const {
	Color mapped_color;

	if (vp.show_out_of_gamut)
		mapped_color = clamp_to_color(raw_color);
	else
		mapped_color = max_to_one(raw_color);

	// gamma correction, uses powc to return a new color with its color values corrected
	if (vp.gamma != 1.0)
		mapped_color = mapped_color.powc(vp.invGamma);

	//have to start from max y coordinate to convert to screen coordinates
	film->setPixel(x, y, (int) (mapped_color.r * 255),
			(int) (mapped_color.g * 255), (int) (mapped_color.b * 255));
}

// ------------------------------------------------------------------ clamp

Color Scene::max_to_one(const Color& c) const {
	float max_value = max(c.r, max(c.g, c.b));

	if (max_value > 1.0)
		return (c / max_value);
	else
		return c;
}

// ------------------------------------------------------------------ clamp_to_color
// Set color to red if any component is greater than one

Color Scene::clamp_to_color(const Color& raw_color) const {
	Color c(raw_color);

	if (raw_color.r > 1.0 || raw_color.g > 1.0 || raw_color.b > 1.0) {
		c.r = 1.0;
		c.g = 0.0;
		c.b = 0.0;
	}

	return (c);
}

Scene::~Scene() {

}
