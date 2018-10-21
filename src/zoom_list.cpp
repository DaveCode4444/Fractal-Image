/*
 * zoom_list.cpp
 *
 *  Created on: Oct 21, 2018
 *      Author: Devang Sawant
 */

#include "../includes/zoom.h"
#include "../includes/zoom_list.h"

#include <utility>

zoom_list::zoom_list(int width, int height) :
    m_width(width),
    m_height(height)
{
}

zoom_list::~zoom_list()
{
}

void zoom_list::add(const zoom &the_zoom)
{
	m_zooms.push_back(the_zoom);
}

std::pair<double, double> zoom_list::do_zoom(int x, int y)
{
	return std::pair<double, double>(0, 0);
}


