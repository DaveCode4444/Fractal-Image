/*
 * Creating a fractal image fractal images
 * main.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: Devang Sawant
 */
#include "../includes/fractal_creator.h"
#include "../includes/zoom.h"

int main()
{
	const int WIDTH = 800;
	const int HEIGHT = 600;

	//creates bitmap, zoom_list, fractal, histogram
	fractal_creator the_fractal_creator(WIDTH, HEIGHT);

	//adds zooms to zoom_list
	the_fractal_creator.add_zoom(zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
	the_fractal_creator.add_zoom(zoom(295, HEIGHT - 202, 0.1));
	the_fractal_creator.add_zoom(zoom(312, HEIGHT - 304, 0.1));

	//calculates total iterations
	the_fractal_creator.calculate_iterations();

	//coloring scheme and sets pixels
	the_fractal_creator.draw_fractal();

	//writes to file
	const std::string filename{"fractal.bmp"};
	the_fractal_creator.write_bitmap(filename);

	return 0;
}
