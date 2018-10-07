/*
 * bitmap.h
 *
 *  Created on: Sep 28, 2018
 *      Author: Devang Sawant
 */

#ifndef INCLUDES_BITMAP_H_
#define INCLUDES_BITMAP_H_

#include "../includes/bitmap_headers/bitmap_file_header.h"
#include "../includes/bitmap_headers/bitmap_info_header.h"

#include <cstdint>
#include <memory>
#include <string>

class bitmap
{
    public:
	    bitmap(int width, int height);
	    virtual ~bitmap();

	    bool write(const std::string &filename);
	    void set_pixel(int x,
	    			   int y,
					   std::uint8_t red,
					   std::uint8_t green,
					   std::uint8_t blue);

    private:
	    bool write_headers_and_pixels_to_file(const std::string &filename,
											  bitmap_headers::bitmap_file_header file_header,
											  bitmap_headers::bitmap_info_header info_header);

	    int m_height;
	    int m_width;

	    std::unique_ptr<std::uint8_t[]> m_pixels; //holds the pixels on the screen
};

#endif /* INCLUDES_BITMAP_H_ */
