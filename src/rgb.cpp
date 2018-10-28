/*
 * rgb.cpp
 *
 *  Created on: Oct 28, 2018
 *      Author: Devang Sawant
 */

#include "../includes/rgb.h"

rgb::rgb(double red, double green, double blue) :
    m_red(red),
	m_green(green),
	m_blue(blue)
{
}

rgb operator-(const rgb &first, const rgb &second)
{
	return rgb(first.m_red - second.m_red, first.m_green - second.m_green, first.m_blue - second.m_blue);
}
