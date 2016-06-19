/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:37:02 by telain            #+#    #+#             */
/*   Updated: 2016/06/18 19:11:37 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	char			*fractal;
	int				bpp;
	int				sl;
	int				endi;
	int				win_x;
	int				win_y;
	double			depth;
	double			zoom;
	int				x;
	int				y;
	double			place_x;
	double			place_y;
	double			r_julia;
	double			i_julia;

}				t_env;

#include <stdio.h>

# include <fcntl.h>
# include <math.h>
# include "../includes/libft.h"
# include "mlx.h"
# define WIN_X 800
# define WIN_Y 600

void			pixel_put(t_env *e, int x, int y, int color);
void			draw_window(t_env *e);
int				choose_color(double i,  t_env *e);
void			do_input(t_env *e, int key);
void			mandelbrot(int x, int y, t_env *e, int i);
void			julia(int x, int y, t_env *e, int i);

#endif
