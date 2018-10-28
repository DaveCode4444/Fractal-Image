/*
 * rgb.h
 *
 *  Created on: Oct 28, 2018
 *      Author: Devang Sawant
 */

#ifndef INCLUDES_RGB_H_
#define INCLUDES_RGB_H_

struct rgb
{
	rgb(double red, double green, double blue);

	double m_red;
	double m_green;
	double m_blue;
};

rgb operator-(const rgb &first, const rgb &second);

#endif /* INCLUDES_RGB_H_ */
