/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fonction.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/07 17:13:30 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/07 17:13:33 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct			s_color
{
	int					red;
	int					green;
	int					blue;
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_frac
{
	double				zoom;
	double				movey;
	double				movex;
	int					maxit;
	double				cre;
	double				cim;
	double				newre;
	double				newim;
	double				oldre;
	double				oldim;
}						t_frac;

typedef struct			s_file
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*ptr_img;
	char				*my_str_img;
	int					bpp;
	int					s_l;
	int					endian;
	int					h_moove;
	int					v_moove;
	t_color				color;
	t_frac				frac;
	void				(*f_a)(struct s_file *e, int x, int y);
	int					th_i;
	int					th_i_m;
	int					tmp_x;
	int					tmp_y;
	int					option;
	char				*name;
	int					ac;
	char				*win_name;
}						t_file;

#endif
