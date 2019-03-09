/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   frac_init.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 15:28:58 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/06 15:29:00 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void init_mlx(t_file *file)
{
	file->tmp_x = 0;
    file->tmp_y = 0;
    file->mlx_ptr = mlx_init();
    file->win_ptr = mlx_new_window(file->mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
    file->ptr_img = mlx_new_image(file->mlx_ptr, WIDTH, HEIGHT);
	file->my_str_img = mlx_get_data_addr(file->ptr_img, &(file->bpp), &(file->s_l)
    , &(file->endian));
	file->color.r = 100;
	file->color.g = 230;
	file->color.b = 255;
}

void init_julia(t_file *file)
{
	file->frac.cRe = -0.7;
	file->frac.cIm = 0.27016;
	file->frac.newRe = 0;
	file->frac.newIm = 0;
	file->frac.oldIm = 0;
	file->frac.oldRe = 0;
	file->frac.moveX = -1.6;
	file->frac.moveY = -0.9;
	file->frac.maxIT = 100;
	file->frac.zoom = 400;
}

void	init_mandelbrot(t_file *file)
{
	file->frac.zoom = 400;
	file->frac.moveX = -2;
	file->frac.moveY = -0.9;
	file->frac.maxIT = 100;
	file->frac.cRe = 0;
	file->frac.cIm = 0;
	file->frac.newRe = 0;
	file->frac.newIm = 0;
	file->frac.oldRe = 0;
	file->frac.oldIm = 0;
}

void	init_burning_ship(t_file *file)
{
	file->frac.zoom = 400;
	file->frac.moveX = -1.8;
	file->frac.moveY = -1.3;
	file->frac.maxIT = 100;
	file->frac.cRe = 0;
	file->frac.cIm = 0;
	file->frac.newRe = 0;
	file->frac.newIm = 0;
	file->frac.oldRe = 0;
	file->frac.oldIm = 0;
}

void	init_buddha(t_file *file)
{
	file->frac.zoom = 400;
	file->frac.moveX = -2;
	file->frac.moveY = -0.9;
	file->frac.maxIT = 100;
	file->frac.cRe = 0;
	file->frac.cIm = 0;
	file->frac.newRe = 0;
	file->frac.newIm = 0;
	file->frac.oldRe = 0;
	file->frac.oldIm = 0;
}
