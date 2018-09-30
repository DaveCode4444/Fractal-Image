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
	bitmap.set_pixel(WIDTH/2, HEIGHT/2, 255, 255, 255);

//	for(int y = 0; y < HEIGHT; y++)
//	{
//		for(int x = 0; x < WIDTH; x++)
//		{
//			bitmap.set_pixel(x, y, 255, 0, 0);
//		}
//	}
	bitmap.write("fractal.bmp");

	std::cout << "Bitmap file created." << std::endl;
	return 0;
}
