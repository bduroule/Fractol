/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/25 17:10:31 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/25 17:10:38 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/include/libft.h"
# include "../minilibx_macos/mlx.h"
# include "struct.h"
# include <math.h>
# include <pthread.h>

# define WIDTH 1280
# define HEIGHT 720
# define THREAD 16
# define SWINDOW WIDTH/ THREAD

/*
** Init
*/
void					init_julia(t_file *file);
void					init_mandelbrot(t_file *file);
void					init_mlx(t_file *file);
void					set_color(t_file *file);
void					init_burning_ship(t_file *file);

/*
** Fractal algo
*/
void					julia_algo(t_file *file, int x, int y);
void					mandelbrot_algo(t_file *file, int x, int y);
void					burning_ship_algo(t_file *file, int x, int y);

/*
** Event
*/
int						deal_key(int key, t_file *file);
int						mouse_press(int key, int x, int y, t_file *file);
int						mouse_moove(int x, int y, t_file *file);

/*
** Multi tread
*/
void					*parc_algo(void *file);
int						multithreads(t_file *file);
void					frac_type(t_file *file, char *str);

/*
** Display
*/
void					get_color(t_file *file, int x, int y, double mu);
void					color_pixel(t_file *file, int x, int y);
void					display(t_file *file);
void					init_color(t_file *file);

/*
** Error
*/
int						out(void *param);
void					frac_error(char *str, t_file *file);

#endif
