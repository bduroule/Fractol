/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   frac_thread.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 15:02:34 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/06 15:02:35 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	*parc_algo(void *vfile)
{
	int		x;
	int		y;
	t_file	*file;

	file = (t_file *)vfile;
	y = file->th_i;
	while (y < file->th_i_m)
	{
		x = 0;
		while (x < WIDTH)
		{
			file->f_a(file, x, y);
			x++;
		}
		y++;
	}
	return (file);
}

int		multithreads(t_file *file)
{
	int			i;
	pthread_t	tread[THREAD];
	t_file		th_file[THREAD];

	i = -1;
	while (++i < THREAD)
	{
		th_file[i] = *file;
		th_file[i].th_i = SWINDOW * i;
		th_file[i].th_i_m = SWINDOW * (i + 1);
		pthread_create(&tread[i], NULL, parc_algo, &th_file[i]);
	}
	i = -1;
	while (++i < THREAD)
		pthread_join(tread[i], NULL);
	return (1);
}
