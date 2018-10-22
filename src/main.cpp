/*
 * This project is on the topic of how to create fractal images
 * main.cpp
 *
 *  Created on: Sep 25, 2018
 *      Author: Devang Sawant
 */
#include "../includes/bitmap.h"
#include "../includes/mandelbrot.h"
#include "../includes/zoom.h"
#include "../includes/zoom_list.h"

#include <cstdint>
#include <iostream>
#include <math.h>
#include <memory>

int main()
{
	const int WIDTH = 800;
	const int HEIGHT = 600;

	bitmap bitmap(WIDTH, HEIGHT); //bitmap object

//	double min = 999999;
//	double max = -999999;
	zoom_list the_zoom_list(WIDTH, HEIGHT);
	the_zoom_list.add(zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
	the_zoom_list.add(zoom(268, HEIGHT - 229, 0.2));

	std::unique_ptr<int[]> histogram(new int[mandelbrot::MAX_ITERATIONS + 1]{0});
	std::unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{0});

	//iterating over the complete bitmap i.e. 800*600, populating histogram and fractal
	for(int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			std::pair<double, double> coordinates = the_zoom_list.do_zoom(x, y);
			double x_fractal = coordinates.first; //scaling for printing the mandelbrot image in somewhat middle of the entire bitmap
			double y_fractal = coordinates.second;
			int iterations = mandelbrot::get_iterations(x_fractal, y_fractal);
			fractal[y*WIDTH + x] = iterations;

			if(iterations != mandelbrot::MAX_ITERATIONS)
			{
			    histogram[iterations]++;
			}
		}
	}

	//total number of iterations, adding all elements of histogram
	int total = 0;
	for(int i = 0; i < mandelbrot::MAX_ITERATIONS; i++)
	{
		total += histogram[i];
	}

	//coloring scheme
	for(int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			std::uint8_t red = 0;
			std::uint8_t green = 0;
			std::uint8_t blue = 0;

			int iterations = fractal[y*WIDTH + x];
			if(iterations != mandelbrot::MAX_ITERATIONS)
			{
				double hue = 0.0;
				for(int i = 0; i <= iterations; i++)
				{
					hue += ((double)histogram[i])/total;
				}
				green = pow(255, hue);
			}
			bitmap.set_pixel(x, y, red, green, blue);
		}
	}

	const std::string filename{"fractal.bmp"};
	bitmap.write(filename);

	std::cout << "Bitmap file created." << std::endl;
	return 0;
}
