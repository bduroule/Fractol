/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   frac_event.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/28 15:48:47 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 13:16:10 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	frac_key(int key, t_file *file)
{
	if (key == 46)
	{
		init_mandelbrot(file);
		file->f_a = &(mandelbrot_algo);
	}
	if (key == 38)
	{
		init_julia(file);
		file->f_a = &(julia_algo);
	}
	if (key == 11)
	{
		init_burning_ship(file);
		file->f_a = &(burning_ship_algo);
	}
}

int		deal_key(int key, t_file *file)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 126)
		file->frac.movey += 0.02;
	if (key == 125)
		file->frac.movey -= 0.02;
	if (key == 124)
		file->frac.movex -= 0.02;
	if (key == 123)
		file->frac.movex += 0.02;
	if (file->frac.maxit > 7)
		if (key == 78)
			file->frac.maxit -= 6;
	if (key == 69)
		file->frac.maxit += 6;
	if (key == 49 && file->option == 1)
		file->option = 0;
	else
		file->option = 1;
	frac_key(key, file);
	display(file);
	return (0);
}

int		mouse_press(int key, int x, int y, t_file *e)
{
	if (!((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT)))
		return (0);
	if (key == 5)
	{
		e->frac.movex = (x / e->frac.zoom + e->frac.movex) - (x /
		(e->frac.zoom * 1.2));
		e->frac.movey = (y / e->frac.zoom + e->frac.movey) - (y /
		(e->frac.zoom * 1.2));
		e->frac.zoom *= 1.2;
	}
	if (key == 4)
	{
		e->frac.movex = (x / e->frac.zoom + e->frac.movex) - (x /
		(e->frac.zoom / 1.2));
		e->frac.movey = (y / e->frac.zoom + e->frac.movey) - (y /
		(e->frac.zoom / 1.2));
		e->frac.zoom /= 1.2;
	}
	if (key == 1)
		set_color(e);
	if (key == 2)
		init_color(e);
	display(e);
	return (0);
}

int		mouse_moove(int x, int y, t_file *file)
{
	if (!((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT) && file->option == 0))
		return (0);
	if (x < file->tmp_x)
		file->frac.cre -= (double)x / 17000;
	if (x > file->tmp_x)
		file->frac.cre += (double)x / 17000;
	if (y < file->tmp_y)
		file->frac.cim -= (double)y / 17000;
	if (y > file->tmp_y)
		file->frac.cim += (double)y / 17000;
	file->tmp_x = x;
	file->tmp_y = y;
	display(file);
	return (0);
}
