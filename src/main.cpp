/*
 * This project is on the topic of how to create fractal images
 * main.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: Devang Sawant
 */
#include "../includes/bitmap.h"
#include "../includes/mandelbrot.h"

#include <cstdint>
#include <iostream>

int main()
{
	const int WIDTH = 800;
	const int HEIGHT = 600;

	bitmap bitmap(WIDTH, HEIGHT); //bitmap object

	double min = 999999;
	double max = -999999;

	//iterating over the complete bitmap i.e. 800*600
	for(int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			double x_fractal = (x - WIDTH/2 - 200) * 2.0/HEIGHT;
			double y_fractal = (y - HEIGHT/2) * 2.0/HEIGHT;

			int iterations = mandelbrot::get_iterations(x_fractal, y_fractal);
			std::uint8_t color = (std::uint8_t)(256 * (double)iterations/mandelbrot::MAX_ITERATIONS);
			color = color * color * color;
			bitmap.set_pixel(x, y, 0, 0, color);

			if(color < min) min = color;
			if(color > max) max = color;
		}
	}

	bitmap.write("fractal.bmp");
	std::cout << "Bitmap file created." << std::endl;
	return 0;
}
