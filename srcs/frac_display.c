/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   frac_display.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 16:30:03 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/26 16:30:23 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		set_color(t_file *file)
{
	file->color.r = rand() % 255;
	file->color.g = rand() % 255;
	file->color.b = rand() % 255;
}

void		get_color(t_file *file, int x, int y, double mu)
{
	file->color.red = (mu / file->frac.maxit) * 2 * (file->color.r % 255);
	file->color.green = (mu / file->frac.maxit) * 2 * (file->color.g % 255);
	file->color.blue = (mu / file->frac.maxit) * 2 * (file->color.b % 255);
	color_pixel(file, x, y);
}

void		color_pixel(t_file *file, int x, int y)
{
	int i;

	i = (x * 4) + (y * (file->s_l));
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		file->my_str_img[i] = (char)file->color.blue;
		file->my_str_img[i + 1] = (char)file->color.green;
		file->my_str_img[i + 2] = (char)file->color.red;
	}
}

void		display(t_file *file)
{
	t_file *e;

	e = file;
	multithreads(file);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr, file->ptr_img, 0, 0);
}
