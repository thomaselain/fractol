/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 16:32:13 by telain            #+#    #+#             */
/*   Updated: 2016/06/17 15:13:19 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *		COMMENTAIRES = MANDELBROT (le reste c'est Julia)
 */

#include "../includes/fractol.h"

int		choose_color(double i, t_env *e)
{
	if (i < e->depth)
		return (0x000000 + i * 0x101010);
	return (0x000000);
}

void	is_fractal(int x, int y, t_env *e)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
	int		i;

	i = 0;
	z_r = 0;
	z_i = 0;
	c_r = (x - WIN_X / 2) / e->zoom + e->place_x;
	c_i = (y - WIN_Y / 2) / e->zoom + e->place_y;
	while (z_r * z_r + z_i * z_i < 4 && i < e->depth)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = (z_i + z_i) * tmp + c_i;
		i++;
	}
	pixel_put(e, (int)x, (int)y, choose_color(i, e));
}

void	draw(t_env *e)
{
	int		x;
	int		y;

	y = -1;
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sl), &(e->endi));
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			is_fractal(x, y, e);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

