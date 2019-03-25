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

void		mandelbrot_algo(t_file *e, int x, int y)
{
	int		i;
	double	co;

	i = 0;
	e->frac.cre = x / e->frac.zoom + e->frac.movex;
	e->frac.cim = y / e->frac.zoom + e->frac.movey;
	e->frac.newre = 0;
	e->frac.newim = 0;
	e->frac.oldre = 0;
	e->frac.oldim = 0;
	while (i < e->frac.maxit)
	{
		e->frac.oldre = e->frac.newre;
		e->frac.oldim = e->frac.newim;
		e->frac.newre = e->frac.oldre * e->frac.oldre - e->frac.oldim *
		e->frac.oldim + e->frac.cre;
		e->frac.newim = 2 * e->frac.oldre * e->frac.oldim + e->frac.cim;
		if ((e->frac.newre * e->frac.newre + e->frac.newim * e->frac.newim) > 4)
			break ;
		i++;
	}
	co = i + 1 - log(log(sqrt((e->frac.newre * e->frac.newre) +
	(e->frac.newim * e->frac.newim)))) + log(4);
	get_color(e, x, y, co);
}

void		julia_algo(t_file *e, int x, int y)
{
	int		i;
	double	co;

	i = 0;
	e->frac.newim = y / e->frac.zoom + e->frac.movey;
	e->frac.newre = x / e->frac.zoom + e->frac.movex;
	while (i < e->frac.maxit)
	{
		e->frac.oldre = e->frac.newre;
		e->frac.oldim = e->frac.newim;
		e->frac.newre = e->frac.oldre * e->frac.oldre - e->frac.oldim *
		e->frac.oldim + e->frac.cre;
		e->frac.newim = 2 * e->frac.oldre * e->frac.oldim + e->frac.cim;
		if ((e->frac.newre * e->frac.newre + e->frac.newim * e->frac.newim) > 4)
			break ;
		i++;
	}
	co = i + 1 - log(log(sqrt((e->frac.newre * e->frac.newre) + (e->frac.newim *
	e->frac.newim)))) + log(4);
	get_color(e, x, y, co);
}

void		burning_ship_algo(t_file *e, int x, int y)
{
	int		i;
	double	co;

	i = 0;
	e->frac.cre = x / e->frac.zoom + e->frac.movex;
	e->frac.cim = y / e->frac.zoom + e->frac.movey;
	e->frac.newre = 0;
	e->frac.newim = 0;
	e->frac.oldre = 0;
	e->frac.oldim = 0;
	while (i < e->frac.maxit)
	{
		e->frac.oldre = e->frac.newre;
		e->frac.oldim = e->frac.newim;
		e->frac.newre = e->frac.oldre * e->frac.oldre - e->frac.oldim
		* e->frac.oldim + e->frac.cre;
		e->frac.newim = 2 * fabs(e->frac.oldre * e->frac.oldim) + e->frac.cim;
		if ((e->frac.newre * e->frac.newre + e->frac.newim * e->frac.newim) > 4)
			break ;
		i++;
	}
	co = i + 1 - log(log(sqrt((e->frac.newre * e->frac.newre) +
	(e->frac.newim * e->frac.newim)))) + 4;
	get_color(e, x, y, co);
}
