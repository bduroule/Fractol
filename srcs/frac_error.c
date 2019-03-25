/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   frac_error.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/21 18:44:57 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 13:16:03 by beduroul    ###    #+. /#+    ###.fr     */
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

void	frac_error(char *str, t_file *file)
{
	free(file);
	write(1, "error : ", 8);
	ft_putendl(str);
	exit(EXIT_SUCCESS);
}
