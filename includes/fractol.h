/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:37:02 by telain            #+#    #+#             */
/*   Updated: 2016/06/23 23:01:53 by telain           ###   ########.fr       */
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
	double			param_r;
	double			param_i;
	int				param;
}				t_env;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# include <fcntl.h>
# include "../includes/keys.h"
# include <math.h>
# include "../includes/libft.h"
# include "mlx.h"
# define WIN_X 800
# define WIN_Y 600

/*
 * draw.c
*/

int				refresh(void *e);
void			draw_window(t_env *e);
void			pixel_put(t_env *e, int x, int y, int color);

/*
 *	fractal.c
*/

int				choose_color(double i,  t_env *e);
void			mandelbrot(int x, int y, t_env *e, int i);
void			julia(int x, int y, t_env *e, int i);
void			burningship(int x, int y, t_env *e, int i);
void			fisheye(int x, int y, t_env *e, int i);

/*
 *	help_display.c
*/

void			help_display(void);

/*
 *	input.c
*/

void			choose_fractal(t_env *e);
void			do_input(t_env *e, int key);
void			change_input(t_env *e, int x, int y, int fct);
int				find_key(int key, void *e);

/*
 *	main.c
*/

int				find_mouse(int x, int y, void *e);
void			new_env(t_env *e);
int				button_pressed(int button, int x, int y, void *e);

#endif
