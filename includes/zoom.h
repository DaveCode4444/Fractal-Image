/*
 * zoom.h
 *
 *  Created on: Oct 21, 2018
 *      Author: Devang Sawant
 */

#ifndef INCLUDES_ZOOM_H_
#define INCLUDES_ZOOM_H_

struct zoom
{
	int x_coordinate{0};
	int y_coordinate{0};
	double m_scale{0.0};

	zoom(int x, int y, double scale) :
		x_coordinate(x),
		y_coordinate(y),
		m_scale(scale)
	{
	}
};

#endif /* INCLUDES_ZOOM_H_ */
