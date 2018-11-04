/*
 * Creating a fractal image
 * main.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: Devang Sawant
 */
#include "../includes/fractal_creator.h"
#include "../includes/rgb.h"
#include "../includes/zoom.h"

#include <iostream>

int main()
{
	//width and height of bitmap
	const int WIDTH = 800;
	const int HEIGHT = 600;

	//creates bitmap, zoom_list, fractal, histogram
	fractal_creator the_fractal_creator(WIDTH, HEIGHT);

	the_fractal_creator.add_color_range(0.0, rgb(0, 0, 0));
	the_fractal_creator.add_color_range(0.3, rgb(255, 0, 0));
	the_fractal_creator.add_color_range(0.5, rgb(255, 255, 0));
	the_fractal_creator.add_color_range(1.0, rgb(255, 255, 255));

	const std::string filename{"fractal.bmp"};
	the_fractal_creator.run(filename);

	return 0;
}
