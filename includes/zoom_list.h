/*
 * zoom_list.h
 *
 *  Created on: Oct 21, 2018
 *      Author: Devang Sawant
 */

#ifndef INCLUDES_ZOOM_LIST_H_
#define INCLUDES_ZOOM_LIST_H_

#include "../includes/zoom.h"

#include <utility>
#include <vector>

class zoom_list
{
	public:
		zoom_list(const int &width, const int &height);
		virtual ~zoom_list();

		void add(const zoom &the_zoom);
		std::pair<double, double> do_zoom(int &x, int &y);

	private:
		std::vector<zoom> m_zooms;

		int m_width;
		int m_height;
		double m_xCenter;
		double m_yCenter;
		double m_scale;
};

#endif /* INCLUDES_ZOOM_LIST_H_ */
