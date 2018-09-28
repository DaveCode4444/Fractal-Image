/*
 * bitmap.cpp
 *
 *  Created on: Sep 28, 2018
 *      Author: sawan
 */

#include "../includes/bitmap.h"

#include <string>

bitmap::bitmap(int height, int width) :
    m_height(height),
	m_width(width)
{
}

bitmap::~bitmap()
{
}

bool bitmap::write(std::string filename)
{
	return false;
}

void bitmap::set_pixel(int x,
	    			   int y,
					   std::uint8_t red,
					   std::uint8_t green,
					   std::uint8_t blue)
{
}




