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

	const std::string filename{"fractal.bmp"};
	the_fractal_creator.run(filename);

	return 0;
}
