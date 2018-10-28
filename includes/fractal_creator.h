/*
 * fractal_creator.h
 *
 *  Created on: Oct 28, 2018
 *      Author: Devang Sawant
 */

#ifndef INCLUDES_FRACTAL_CREATOR_H_
#define INCLUDES_FRACTAL_CREATOR_H_

#include "../includes/bitmap.h"
#include "../includes/zoom.h"
#include "../includes/zoom_list.h"

#include <memory>
#include <string>

class fractal_creator
{
    public:
	    fractal_creator(const int &width, const int &height);
	    virtual ~fractal_creator();

	    void add_zoom(const zoom &the_zoom);
	    void calculate_iterations();
	    void draw_fractal();
	    void write_bitmap(const std::string &filename);

    private:
	    const int m_width;
	    const int m_height;
	    int m_total_iterations;

	    bitmap m_bitmap;
	    zoom_list m_zoom_list;
	    std::unique_ptr<int[]> m_histogram;
	    std::unique_ptr<int[]> m_fractal;
};

#endif /* INCLUDES_FRACTAL_CREATOR_H_ */
