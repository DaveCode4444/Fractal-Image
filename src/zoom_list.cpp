/*
 * zoom_list.cpp
 *
 *  Created on: Oct 21, 2018
 *      Author: Devang Sawant
 */

#include "../includes/zoom.h"
#include "../includes/zoom_list.h"

#include <utility>

zoom_list::zoom_list(const int &width, const int &height) :
	m_width(width),
	m_height(height),
	m_xCenter{0.0},
	m_yCenter{0.0},
	m_scale{1.0}
{
}

zoom_list::~zoom_list()
{
}

void zoom_list::add(const zoom &the_zoom)
{
	m_zooms.push_back(the_zoom);

	m_xCenter += (the_zoom.x_coordinate - m_width/2) * m_scale;
	m_yCenter += (the_zoom.y_coordinate - m_height/2) * m_scale;
	m_scale *= the_zoom.m_scale;
}

std::pair<double, double> zoom_list::do_zoom(int &x, int &y)
{
	double x_fractal = (x - m_width/2) * m_scale + m_xCenter;
	double y_fractal = (y - m_height/2) * m_scale + m_yCenter;

	return std::pair<double, double>(x_fractal, y_fractal);
}
