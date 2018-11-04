/*
 * fractal_creator.h
 *
 *  Created on: Oct 28, 2018
 *      Author: Devang Sawant
 */

#ifndef INCLUDES_FRACTAL_CREATOR_H_
#define INCLUDES_FRACTAL_CREATOR_H_

#include "../includes/bitmap.h"
#include "../includes/rgb.h"
#include "../includes/zoom.h"
#include "../includes/zoom_list.h"

#include <memory>
#include <string>
#include <vector>

class fractal_creator
	{
	public:
		fractal_creator(const int &width, const int &height);
		virtual ~fractal_creator();

		void run(const std::string &filename);
		void add_color_range(double range_end, const rgb &color);
		int get_range(int iterations) const;

	private:
		void add_zoom(const zoom &the_zoom);
		void calculate_range_totals();
		void calculate_iterations();
		void draw_fractal();
		void write_bitmap(const std::string &filename);

		const int m_width;
		const int m_height;
		int m_total_iterations;
		bool m_got_first_range;
		std::vector<int> m_ranges;
		std::vector<rgb> m_colors;
		std::vector<int> m_range_totals;

		bitmap m_bitmap;
		zoom_list m_zoom_list;
		std::unique_ptr<int[]> m_histogram;
		std::unique_ptr<int[]> m_fractal;
};

#endif /* INCLUDES_FRACTAL_CREATOR_H_ */
