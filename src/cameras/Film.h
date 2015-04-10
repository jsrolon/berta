/*
 * Film.h
 *
 *  Created on: Apr 10, 2015
 *      Author: jsrolon
 */

#ifndef CAMERAS_FILM_H_
#define CAMERAS_FILM_H_

#include "berta.h"
#include "color.h"

class Film {
private:
	bool show_out_of_gamut;
	float gamma; // gamma correction factor
	float invGamma; // the inverse of the gamma correction factor
public:
	int hres;
	int vres;

	RenderThread* renderThread;

	Film();

	Color max_to_one(const Color& c) const;
	Color clamp_to_color(const Color& raw_color) const;
	void setPixelColor(const int x, const int y, const Color& color);
	void setRenderThread(RenderThread* const rt);

	virtual ~Film();
};

#endif /* CAMERAS_FILM_H_ */
