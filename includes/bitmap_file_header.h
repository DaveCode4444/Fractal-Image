/*
 * bitmap_file_header.h
 *
 *  Created on: Sep 25, 2018
 *      Author: Devang Sawant
 */

#ifndef INCLUDES_BITMAP_FILE_HEADER_H_
#define INCLUDES_BITMAP_FILE_HEADER_H_

#include <cstdint>

#pragma pack(2) //makes struct exactly as it is in memory, removes extra padding

struct bitmap_file_header
{
	char header[2]{'B', 'M'};
	std::int32_t file_size;
	std::int32_t reserved{0};
	std::int32_t data_offset;
};

#endif /* INCLUDES_BITMAP_FILE_HEADER_H_ */
