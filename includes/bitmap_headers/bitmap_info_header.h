/*
 * bitmap_info_header.h
 *
 *  Created on: Sep 28, 2018
 *      Author: Devang Sawant
 */

#ifndef INCLUDES_BITMAP_INFO_HEADER_H_
#define INCLUDES_BITMAP_INFO_HEADER_H_

#include <cstdint>

#pragma pack(2)

namespace bitmap_headers
{
struct bitmap_info_header
{
	std::uint32_t header_size{40}; //add all bytes in this struct, they add upto 40
	std::uint32_t width; //width of bitmap
	std::uint32_t height;
	std::uint16_t planes{1};
	std::uint16_t bits_per_pixel{24}; //one byte for each color (RGB)
	std::uint32_t compression{0};
	std::uint32_t data_size{0};
	std::uint32_t horizontal_resolution{2400};
	std::uint32_t vertical_resolution{2400};
	std::uint32_t colors{0};
	std::uint32_t important_colors{0};
};
}

#endif /* INCLUDES_BITMAP_INFO_HEADER_H_ */
