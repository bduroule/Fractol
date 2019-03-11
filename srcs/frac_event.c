/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   frac_event.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/28 15:48:47 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/28 15:48:52 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void				frac_key(int key, t_file *file)
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

int             deal_key(int key, t_file *file)
{
    if (key == 53)
		exit(EXIT_SUCCESS);
    if (key == 126)
		file->frac.moveY += 0.02;
	if (key == 125)
		file->frac.moveY -= 0.02;
	if (key == 123)
		file->frac.moveX += 0.02;
	if (key == 124)
		file->frac.moveX -= 0.02;
	if (key == 78)
		file->frac.maxIT -= 10;
	if (key == 69)
		file->frac.maxIT += 10;
	frac_key(key, file);
   display(file);
    return (0);
}

int				mouse_press(int key, int x, int y, t_file *file)
{
	if (!((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT)))
		return (0);
	if (key == 4)
	{
		file->frac.zoom += 8;
		//file->frac.moveX = x / file->frac.zoom - file->frac.moveX;
		//file->frac.moveY = y / file->frac.zoom - file->frac.moveY;
	}
	if (key == 5)
	{
		file->frac.zoom -= 1;
		//file->frac.moveX = file->frac.zoom + file->frac.moveX / x;
		//file->frac.moveY = y / file->frac.zoom + file->frac.moveY;
	}
	if (key == 1)
		set_color(file);
	if (key == 2)
		init_color(file);
	display(file);
	return (0);
}

int mouse_moove(int x, int y, t_file *file)
{
	if (!((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT)))
		return (0);
	if (x < file->tmp_x)
		file->frac.cRe -= 0.02;
	if (x > file->tmp_x)
		file->frac.cRe += 0.02;
	if (y < file->tmp_y)
		file->frac.cIm -= 0.02;
	if (y > file->tmp_y)
		file->frac.cIm += 0.02;
	file->tmp_x = x;
	file->tmp_y = y;
	display(file);
	return (0);
}
