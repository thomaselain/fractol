/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 16:32:13 by telain            #+#    #+#             */
/*   Updated: 2016/06/06 22:20:59 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		choose_color(double i, t_env *e)
{
	int		color;

	color = 0x000000;
	if (i < e->depth * 1 / 4)
		return (0x000000 + 0x0f0000 * i);
	else if (i < e->depth * 2 / 4)
		return (0x3f0000 + 0x0f0000 * i);
	else if (i < e->depth * 3 / 4)
		return (0x7e0000 + 0x0f0000 * i);
	else if (i < e->depth)
		return (0xbd0000 + 0x0f0000 * i);
	else
		return (0xff0000);
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
	c_r = X1 + (X2 - X1) / WIN_X * x;
	c_i = Y1 + (Y2 - Y1) / WIN_Y * y;
	z_r = 0;
	z_i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < e->depth)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
		pixel_put(e, (int)x, (int)y, choose_color(i, e));
	}
}

void	draw(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sl), &(e->endi));
	while (y++ < WIN_Y)
	{
		x = 0;
		while (x++ < WIN_X)
		{
			is_fractal(x, y, e);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
