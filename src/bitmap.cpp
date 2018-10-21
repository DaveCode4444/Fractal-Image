/*
 * bitmap.cpp
 *
 *  Created on: Sep 28, 2018
 *      Author: Devang Sawant
 */

#include "../includes/bitmap.h"
#include "../includes/bitmap_headers/bitmap_file_header.h"
#include "../includes/bitmap_headers/bitmap_info_header.h"

#include <fstream>
#include <string>

bitmap::bitmap(const int &width, const int &height) :
    m_height(height),
	m_width(width),
	m_pixels(new std::uint8_t[width * height * 3]{ }) //each pixel has 3 components (R, G, B)
{
}

bitmap::~bitmap()
{
}

bool bitmap::write(const std::string &filename)
{
	bitmap_headers::bitmap_file_header file_header;
	bitmap_headers::bitmap_info_header info_header;

	file_header.file_size = sizeof(bitmap_headers::bitmap_file_header) + sizeof(bitmap_headers::bitmap_info_header) + (m_width*m_height*3);
	file_header.data_offset = sizeof(bitmap_headers::bitmap_file_header) + sizeof(bitmap_headers::bitmap_info_header);

	info_header.width = m_width;
	info_header.height = m_height;

	bool write_to_file_successful = write_headers_and_pixels_to_file(filename,
															         file_header,
															         info_header);

	return write_to_file_successful;
}

bool bitmap::write_headers_and_pixels_to_file(const std::string &filename,
		                                      bitmap_headers::bitmap_file_header file_header,
										      bitmap_headers::bitmap_info_header info_header)
{
	std::ofstream file;
	file.open(filename, std::ios::out | std::ios::binary);

	if(!file)
	{
		return false;
	}

	file.write((char *)&file_header, sizeof(file_header));
	file.write((char *)&info_header, sizeof(info_header));
	file.write((char *)m_pixels.get(), m_width*m_height*3);

	file.close();

	if(!file)
	{
		return false;
	}
	return true;
}

void bitmap::set_pixel(int x,
	    			   int y,
					   std::uint8_t red,
					   std::uint8_t green,
					   std::uint8_t blue)
{
	std::uint8_t *pixel = m_pixels.get(); //get raw pointer to the array of pixels

	pixel += (y * 3) * m_width + (x * 3); //navigate to the pixel location
	pixel[0] = blue;  // set its 3 components
	pixel[1] = green;
	pixel[2] = red;
}




