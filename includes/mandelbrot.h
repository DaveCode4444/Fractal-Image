/*
 * mandelbrot.h
 *
 *  Created on: Oct 1, 2018
 *      Author: Devang Sawant
 */

#ifndef INCLUDES_MANDELBROT_H_
#define INCLUDES_MANDELBROT_H_

class mandelbrot
{
    public:
	    mandelbrot();
	    virtual ~mandelbrot();

	    static int get_iterations(double &x, double &y);

	    static const int MAX_ITERATIONS = 1000;
};

#endif /* INCLUDES_MANDELBROT_H_ */
