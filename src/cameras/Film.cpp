/*
 * Film.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: jsrolon
 */

#include <cameras/Film.h>
#include "wxraytracer.h"

Film::Film() :
		hres(600), vres(600), show_out_of_gamut(false), gamma(1.0f), invGamma(
				1.0f) {
}

/**
 * Sends the pixel color to the gui so that it may be shown on screen
 * @param x The x position of the pixel in the view plane
 * @param y The y position of the pixel in the view plane
 * @param raw_color The computed raw color of the pixel
 */
void Film::setPixelColor(const int x, const int y, const Color& raw_color) {
	Color mapped_color;

	if (show_out_of_gamut)
		mapped_color = clamp_to_color(raw_color);
	else
		mapped_color = max_to_one(raw_color);

	// gamma correction, uses powc to return a new color with its color values corrected
	if (gamma != 1.0)
		mapped_color = mapped_color.powc(invGamma);

	//have to start from max y coordinate to convert to screen coordinates
	renderThread->setPixel(x, y, (int) (mapped_color.r * 255),
			(int) (mapped_color.g * 255), (int) (mapped_color.b * 255));
}

void Film::setRenderThread(RenderThread * const rt) {
	renderThread = rt;
}

// ------------------------------------------------------------------ clamp

Color Film::max_to_one(const Color& c) const {
	float max_value = max(c.r, max(c.g, c.b));

	if (max_value > 1.0)
		return (c / max_value);
	else
		return c;
}

// ------------------------------------------------------------------ clamp_to_color
// Set color to red if any component is greater than one

Color Film::clamp_to_color(const Color& raw_color) const {
	Color c(raw_color);

	if (raw_color.r > 1.0 || raw_color.g > 1.0 || raw_color.b > 1.0) {
		c.r = 0.0;
		c.g = 1.0;
		c.b = 0.0;
	}

	return (c);
}

Film::~Film() {
	// TODO Auto-generated destructor stub
}
