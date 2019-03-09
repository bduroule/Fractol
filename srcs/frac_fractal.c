/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   frac_fractal.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 15:38:11 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/06 15:38:12 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_algo(t_file *e, int x, int y)
{
	double i;
	double co;

	i = 0;
	e->frac.cRe = x / e->frac.zoom + e->frac.moveX;
	e->frac.cIm = y / e->frac.zoom + e->frac.moveY;
	e->frac.newRe = e->frac.newIm = e->frac.oldRe = e->frac.oldIm = 0;
	while (i < e->frac.maxIT)
	{
		e->frac.oldRe = e->frac.newRe;
		e->frac.oldIm = e->frac.newIm;
		e->frac.newRe = e->frac.oldRe * e->frac.oldRe - e->frac.oldIm *
        e->frac.oldIm + e->frac.cRe;
		e->frac.newIm = 2 * e->frac.oldRe * e->frac.oldIm + e->frac.cIm;
		if((e->frac.newRe * e->frac.newRe + e->frac.newIm * e->frac.newIm) > 4)
			break;
		i++;
	}
	co = i + 1 - log(log(sqrt((e->frac.newRe * e->frac.newRe) + (e->frac.newIm * e->frac.newIm)))) + 4;
	//co = i + 1 - log(log((e->frac.newIm * e->frac.newIm) + (e->frac.newRe * e->frac.newRe))) + log(2);
	get_color(e, x, y, co);
}

void    julia_algo(t_file *e, int x, int y)
{
    double i;
	double co;

    i = 0;

    e->frac.newIm = y / e->frac.zoom + e->frac.moveY;
	e->frac.newRe = x / e->frac.zoom + e->frac.moveX;
    while(i < e->frac.maxIT)
    {
        e->frac.oldRe = e->frac.newRe;
        e->frac.oldIm = e->frac.newIm;
        e->frac.newRe = e->frac.oldRe * e->frac.oldRe - e->frac.oldIm *
        e->frac.oldIm +e->frac.cRe;
        e->frac.newIm = 2 * e->frac.oldRe * e->frac.oldIm + e->frac.cIm;
        if ((e->frac.newRe * e->frac.newRe + e->frac.newIm * e->frac.newIm) > 4)
          break;
        i++;
    }
co = i + 1 - log(log(sqrt((e->frac.newRe * e->frac.newRe) + (e->frac.newIm * e->frac.newIm)))) + 4;	
    /*e->color.blue = (i / 256) * e->frac.maxIT;
    e->color.green = (int)(i * e->frac.maxIT / 55);
    e->color.red = (int)(i / 255);*/
	get_color(e, x, y, co);
}

void burning_ship_algo(t_file *e, int x, int y)
{
	double i;
	double co;

	i = 0;
	e->frac.cRe = x  /e->frac.zoom + e->frac.moveX;
	e->frac.cIm = y / e->frac.zoom + e->frac.moveY;
	e->frac.newRe = e->frac.newIm = e->frac.oldRe = e->frac.oldIm = 0;
	while (i < e->frac.maxIT)
	{
		e->frac.oldRe = e->frac.newRe;
		e->frac.oldIm = e->frac.newIm;
		e->frac.newRe = e->frac.oldRe * e->frac.oldRe - e->frac.oldIm * e->frac.oldIm
		+ e->frac.cRe;
		e->frac.newIm = 2 * fabs(e->frac.oldRe * e->frac.oldIm) + e->frac.cIm;
		if((e->frac.newRe * e->frac.newRe + e->frac.newIm * e->frac.newIm) > 4)
			break;
		i++;
	}
	co = i + 1 - log(log(sqrt((e->frac.newRe * e->frac.newRe) + (e->frac.newIm * e->frac.newIm)))) + 4;
	get_color(e, x, y, i);
    /*e->color.blue = (i / 255) * e->frac.maxIT;
    e->color.green = (int)(i * e->frac.maxIT / 200);
    e->color.red = (int)(i / 250);*/		
	color_pixel(e, x, y);
}

void    buddha_algo(t_file *e, int x, int y)
{
    double i;
	double co;

	i = 0;
	e->frac.cRe = x  /e->frac.zoom + e->frac.moveX;
	e->frac.cIm = y / e->frac.zoom + e->frac.moveY;
	e->frac.newRe = e->frac.newIm = e->frac.oldRe = e->frac.oldIm = 0;
	while (i < e->frac.maxIT)
	{
		e->frac.oldRe = e->frac.newRe;
		e->frac.oldIm = e->frac.newIm;
		e->frac.newRe = e->frac.oldRe * e->frac.oldRe - e->frac.oldIm *
        e->frac.oldIm + e->frac.cRe;
		e->frac.newIm = 2 * e->frac.oldRe * e->frac.oldIm + e->frac.cIm;
		if((e->frac.newRe * e->frac.newRe + e->frac.newIm * e->frac.newIm) > 4)
			break;
		i++;
	}
	co = i + 1 - log(log((e->frac.newIm * e->frac.newIm) + (e->frac.newRe * e->frac.newRe))) + log(2);
    e->color.blue = (co / 255) * e->frac.maxIT;
    e->color.green = (int)(co * e->frac.maxIT / 200);
    e->color.red = (int)(co / 250);			
	color_pixel(e, x, y);
}
