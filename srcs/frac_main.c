/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   frac_main.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/25 17:11:00 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/25 17:11:01 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		out(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
	return (0);
}

void frac_error(char *str)
{
    write(1, "error : ", 8);
    ft_putendl(str);
    exit(EXIT_SUCCESS);
}

void       frac_type(t_file *file, char **av)
{
    if (ft_strcmp("julia", av[1]) == 0)
    {
        init_julia(file);
        file->f_a = &(julia_algo);
    }
    if (ft_strcmp("mandelbrot", av[1]) == 0)
    {
        init_mandelbrot(file);
        file->f_a = &(mandelbrot_algo);
    }
    if (ft_strcmp("burning_ship", av[1]) == 0)
    {
        init_burning_ship(file);
        file->f_a = &(burning_ship_algo);
    }
    if (ft_strcmp("buddha", av[1]) == 0)
    {
        init_burning_ship(file);
        file->f_a = &(buddha_algo);
    }
}

int main(int ac, char **av)
{
    t_file *file;
    (void)av;

    if (ac != 2)
        return(write(1, "Usage : ./fractol [name] <julia, mandelbrot>\n", 45));
    if (!(file = (t_file *)malloc(sizeof(t_file))))
        return (0);
    if (ft_strcmp("mandelbrot", av[1]) != 0 && ft_strcmp("julia", av[1]) != 0
    && ft_strcmp("burning_ship", av[1]) != 0 && ft_strcmp("buddha", av[1]) != 0)
        frac_error("wrong name");
    frac_type(file, av);
    init_mlx(file);
    display(file);
    mlx_hook(file->win_ptr, 17, 0, out, file);
    mlx_hook(file->win_ptr, 2, 0, deal_key, file);
    mlx_hook(file->win_ptr, 6, 0, mouse_moove, file);
    mlx_hook(file->win_ptr, 4, 0, mouse_press, file);
    mlx_loop(file->mlx_ptr);
    return (0);
}
