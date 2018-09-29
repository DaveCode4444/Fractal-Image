/*
 * bitmap.cpp
 *
 *  Created on: Sep 28, 2018
 *      Author: sawan
 */

#include "../includes/bitmap.h"
#include "../includes/bitmap_headers/bitmap_file_header.h"
#include "../includes/bitmap_headers/bitmap_info_header.h"

#include <string>

bitmap::bitmap(int height, int width) :
    m_height(height),
	m_width(width),
	m_pixels(new std::uint8_t[width * height * 3]) //each pixel has 3 components (R, G, B)
{
}

bitmap::~bitmap()
{
}

bool bitmap::write(std::string filename)
{
	bitmap_headers::bitmap_file_header file_header;
	bitmap_headers::bitmap_info_header info_header;

	file_header.file_size = sizeof(bitmap_headers::bitmap_file_header) + sizeof(bitmap_headers::bitmap_info_header) + (m_width*m_height*3);
	file_header.data_offset = sizeof(bitmap_headers::bitmap_file_header) + sizeof(bitmap_headers::bitmap_info_header);

	info_header.width = m_width;
	info_header.height = m_height;

	return false;
}

void bitmap::set_pixel(int x,
	    			   int y,
					   std::uint8_t red,
					   std::uint8_t green,
					   std::uint8_t blue)
{
}




