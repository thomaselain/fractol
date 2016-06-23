/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 14:54:55 by telain            #+#    #+#             */
/*   Updated: 2016/06/23 23:18:11 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		choose_color(double i, t_env *e)
{
	if (i < e->depth)
		return (0x000020 + i * 0x000008);
	return (0xffffff);
}

void	mandelbrot(int x, int y, t_env *e, int i)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;

	i = 0;
	z_r = e->param_r;
	z_i = e->param_i;
	c_r = (x - WIN_X / 2) / e->zoom + e->place_x;
	c_i = (y - WIN_Y / 2) / e->zoom + e->place_y;
	while (z_r * z_r + z_i * z_i < 4 && i < e->depth)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = (z_i + z_i) * tmp + c_i;
		i++;
	}
	pixel_put(e, x, y, choose_color(i, e));
}

void	julia(int x, int y, t_env *e, int i)
{
	double	z_r;
	double	z_i;
	double	tmp;
	double	tmp2;

	i = 0;
	z_r = (x - WIN_X / 2) / e->zoom + e->place_x;
	z_i = (y - WIN_Y / 2) / e->zoom + e->place_y;
	while (z_r * z_r + z_i * z_i < 4 && i < e->depth)
	{
		tmp = z_r;
		tmp2 = z_i;
		z_r = z_r * z_r - z_i * z_i + e->param_r;
		z_i = (tmp + tmp) * tmp2 + e->param_i;
		i++;
	}
	pixel_put(e, x, y, choose_color(i, e));
}

void	fisheye(int x, int y, t_env *e, int i)
{
	double	z_r;
	double	z_i;
	double	tmp;
	double	tmp2;

	i = 0;
	z_r = (x - WIN_X / 2) / e->zoom + e->place_x;
	z_i = (y - WIN_Y / 2) / e->zoom + e->place_y;
	while (z_r * z_r + z_i * z_i < 4 && i < e->depth)
	{
		tmp = z_r;
		tmp2 = z_i;
		z_r = sin(z_r * z_r - z_i * z_i + e->param_r);
		z_i = (tmp + tmp) * tmp2 + e->param_i;
		i++;
	}
	pixel_put(e, x, y, choose_color(i, e));
}

void	burningship(int x, int y, t_env *e, int i)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;

	i = 0;
	z_r = 0;
	z_i = 0;
	c_r = (x - WIN_X / 2) / e->zoom + e->place_x;
	c_i = (y - WIN_Y / 2) / e->zoom + e->place_y;
	while (z_r * z_r + z_i * z_i < 4 && i < e->depth)
	{
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * fabs((z_i)) * fabs(tmp) + c_i;
		tmp = z_r;
		i++;
	}
	pixel_put(e, x, y, choose_color(i, e));
}
