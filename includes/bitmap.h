/*
 * bitmap.h
 *
 *  Created on: Sep 28, 2018
 *      Author: Devang Sawant
 */

#ifndef INCLUDES_BITMAP_H_
#define INCLUDES_BITMAP_H_

#include <cstdint>
#include <string>

class bitmap
{
    public:
	    bitmap(int height, int width);
	    virtual ~bitmap();

	    bool write(std::string filename);
	    void set_pixel(int x,
	    			   int y,
					   std::uint8_t red,
					   std::uint8_t green,
					   std::uint8_t blue);

    private:
	    int m_height;
	    int m_width;
};

#endif /* INCLUDES_BITMAP_H_ */
