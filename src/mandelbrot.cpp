/*
 * mandelbrot.cpp
 *
 *  Created on: Oct 1, 2018
 *      Author: Devang Sawant
 */
#include "../includes/mandelbrot.h"

#include <complex>

mandelbrot::mandelbrot()
{
}

mandelbrot::~mandelbrot()
{
}

int mandelbrot::get_iterations(double x, double y)
{
	std::complex<double> z = 0; //complex number
	std::complex<double> c(x, y);

	int iterations = 0;
	while(iterations < MAX_ITERATIONS)
	{
		z = z*z + c;
		if(abs(z) > 2)
		{
			break;
		}
		++iterations;
	}
 	return iterations;
}


