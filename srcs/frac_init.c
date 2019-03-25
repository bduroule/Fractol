/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   frac_init.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 15:28:58 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 13:16:28 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_file *e)
{
	e->tmp_x = 0;
	e->tmp_y = 0;
	e->option = 0;
	e->win_name = ft_strjoin("Fract'ol - ", e->name);
	e->mlx_ptr = mlx_init();
	e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT, e->win_name);
	e->ptr_img = mlx_new_image(e->mlx_ptr, WIDTH, HEIGHT);
	e->my_str_img = mlx_get_data_addr(e->ptr_img, &(e->bpp), &(e->s_l)
			, &(e->endian));
	init_color(e);
}

void	init_color(t_file *file)
{
	file->color.r = 8;
	file->color.g = 155;
	file->color.b = 183;
}

void	init_julia(t_file *file)
{
	file->frac.cre = -0.7;
	file->frac.cim = 0.27016;
	file->frac.newre = 0;
	file->frac.newim = 0;
	file->frac.oldim = 0;
	file->frac.oldre = 0;
	file->frac.movex = -1.6;
	file->frac.movey = -0.9;
	file->frac.maxit = 100;
	file->frac.zoom = 400;
}

void	init_mandelbrot(t_file *file)
{
	file->frac.zoom = 400;
	file->frac.movex = -2;
	file->frac.movey = -0.9;
	file->frac.maxit = 102;
	file->frac.cre = 0;
	file->frac.cim = 0;
	file->frac.newre = 0;
	file->frac.newim = 0;
	file->frac.oldre = 0;
	file->frac.oldim = 0;
}

void	init_burning_ship(t_file *file)
{
	file->frac.zoom = 400;
	file->frac.movex = -1.8;
	file->frac.movey = -1.3;
	file->frac.maxit = 100;
	file->frac.cre = 0;
	file->frac.cim = 0;
	file->frac.newre = 0;
	file->frac.newim = 0;
	file->frac.oldre = 0;
	file->frac.oldim = 0;
}
