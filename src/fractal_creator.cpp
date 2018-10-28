/*
 * fractal_creator.cpp
 *
 *  Created on: Oct 28, 2018
 *      Author: Devang Sawant
 */
#include "../includes/fractal_creator.h"
#include "../includes/mandelbrot.h"

#include <iostream>
#include <math.h>
#include <memory>

fractal_creator::fractal_creator(const int &width, const int &height) :
    m_width{width},
    m_height{height},
	m_total_iterations{0},
	m_bitmap{width, height},
    m_zoom_list{width, height},
    m_histogram(new int[mandelbrot::MAX_ITERATIONS + 1]{0}),
    m_fractal(new int[m_width * m_height]{0})
{
}

fractal_creator::~fractal_creator()
{
}

void fractal_creator::add_zoom(const zoom &the_zoom)
{
	m_zoom_list.add(the_zoom);
}

void fractal_creator::calculate_iterations()
{
	//iterating over the complete bitmap i.e. 800*600, populating histogram and fractal
	for(int y = 0; y < m_height; y++)
	{
		for(int x = 0; x < m_width; x++)
		{
			std::pair<double, double> coordinates = m_zoom_list.do_zoom(x, y);
			double x_fractal = coordinates.first; //scaling for printing the mandelbrot image in somewhat middle of the entire bitmap
			double y_fractal = coordinates.second;
			int iterations = mandelbrot::get_iterations(x_fractal, y_fractal);
			m_fractal[y*m_width + x] = iterations;

			if(iterations != mandelbrot::MAX_ITERATIONS)
			{
				m_histogram[iterations]++;
			}
		}
	}

	//total number of iterations, adding all elements of histogram
	for(int i = 0; i < mandelbrot::MAX_ITERATIONS; i++)
	{
		m_total_iterations += m_histogram[i];
	}
}

void fractal_creator::draw_fractal()
{
	for(int y = 0; y < m_height; y++)
	{
		for(int x = 0; x < m_width; x++)
		{
			std::uint8_t red = 0;
			std::uint8_t green = 0;
			std::uint8_t blue = 0;

			int iterations = m_fractal[y*m_width + x];
			if(iterations != mandelbrot::MAX_ITERATIONS)
			{
				double hue = 0.0;
				for(int i = 0; i <= iterations; i++)
				{
					hue += ((double)m_histogram[i])/m_total_iterations;
				}
				green = hue * 255;
			}
			m_bitmap.set_pixel(x, y, red, green, blue);
		}
	}
}

void fractal_creator::write_bitmap(const std::string &filename)
{
	m_bitmap.write(filename);
	std::cout << "Finished Writing Bitmap file Successfully." << std::endl;
}
