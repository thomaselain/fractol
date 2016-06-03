/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:37:02 by telain            #+#    #+#             */
/*   Updated: 2016/06/01 17:09:53 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			win_x;
	int			win_y;
	int			depth;
	int			zoom_x;
	int			zoom_y;
}				t_env;

# include <fcntl.h>
# include <math.h>
# include "../includes/libft.h"
# include "mlx.h"
# define BLACK 0x000000
# define DARKBLUE 0x03224c
# define LIGHTBLUE 0x0131b4
# define YELLOW 0xf6dc12
# define GREEN 0x3a9d23
# define BROWN 0x88421d
# define WHITE 0xffffff
# define WIN_X 800
# define WIN_Y 600
# define X1 -2
# define X2 1.25
# define Y1 -1.25
# define Y2 1.25

void			draw(t_env *e);
void			do_input(t_env *e, int key);
#endif
