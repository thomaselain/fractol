/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:37:02 by telain            #+#    #+#             */
/*   Updated: 2016/06/06 20:42:56 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct	s_env
{
	unsigned long	color;
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				sl;
	int				endi;
	char			*data;
	int				win_x;
	int				win_y;
	int				depth;
	int				zoom_x;
	int				zoom_y;
	int				x;
	int				y;
	int				r;
	int				g;
	int				b;
}				t_env;

# include <fcntl.h>
# include <math.h>
# include "../includes/libft.h"
# include "mlx.h"
# define WIN_X 800
# define WIN_Y 600
# define X1 -2
# define X2 1.25
# define Y1 -1.25
# define Y2 1.25

void			pixel_put(t_env *e, int x, int y, int color);
void			draw(t_env *e);
int				choose_color(double i,  t_env *e);
void			do_input(t_env *e, int key);
void			is_fractal(int x, int y, t_env *e);

#endif
