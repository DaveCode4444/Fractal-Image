/*
 * This project is on the topic of how to create fractal images
 * main.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: Devang Sawant
 */
#include "../includes/bitmap.h"

#include <iostream>

int main()
{
	const int WIDTH = 800;
	const int HEIGHT = 600;

	bitmap bitmap(WIDTH, HEIGHT); //bitmap object

	double min = 999999;
	double max = -999999;

	for(int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			double x_fractal = (x - WIDTH/2) * 2.0/WIDTH;
			//double y_fractal = (y - HEIGHT/2) * 2.0/HEIGHT;

			if(x_fractal < min) min = x_fractal;
			if(x_fractal > max) max = x_fractal;
			//bitmap.set_pixel(x, y, 255, 0, 0);
		}
	}

	std::cout << min << " " << max << std::endl;
	bitmap.write("fractal.bmp");

	std::cout << "Bitmap file created." << std::endl;
	return 0;
}
