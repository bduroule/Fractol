/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   frac_main.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/25 13:39:21 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 13:39:23 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	frac_type(t_file *file, char *str)
{
	if (ft_strcmp("julia", str) == 0)
	{
		init_julia(file);
		file->f_a = &(julia_algo);
	}
	if (ft_strcmp("mandelbrot", str) == 0)
	{
		init_mandelbrot(file);
		file->f_a = &(mandelbrot_algo);
	}
	if (ft_strcmp("burning_ship", str) == 0)
	{
		init_burning_ship(file);
		file->f_a = &(burning_ship_algo);
	}
}

void	hook_loop(t_file *file)
{
	mlx_hook(file->win_ptr, 17, 0, out, file);
	mlx_hook(file->win_ptr, 2, 0, deal_key, file);
	mlx_hook(file->win_ptr, 6, 0, mouse_moove, file);
	mlx_hook(file->win_ptr, 4, 0, mouse_press, file);
	mlx_loop(file->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_file *file;

	if (ac != 2)
		return (write(1, "Usage : ./fractol [name] <julia, mandelbrot>\n", 45));
	if (!(file = (t_file *)malloc(sizeof(t_file))))
		frac_error("bad allocation", file);
	if (ft_strcmp("mandelbrot", av[1]) != 0 && ft_strcmp("julia", av[1]) != 0
			&& ft_strcmp("burning_ship", av[1]) != 0)
		frac_error("wrong name", file);
	file->name = ft_strdup(av[1]);
	file->ac = ac;
	frac_type(file, file->name);
	init_mlx(file);
	display(file);
	hook_loop(file);
	return (0);
}
