/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 14:54:55 by telain            #+#    #+#             */
/*   Updated: 2016/06/19 02:06:22 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    draw_window(t_env *e)
{
	int     x;
	int     y;
	void    (*f)(int x, int y, t_env *e, int i);

	y = -1;
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sl), &(e->endi));
	if (ft_strcmp(e->fractal, "mandelbrot") == 0)
		(f) = &mandelbrot;
	else if (ft_strcmp(e->fractal, "julia") == 0)
		(f) = &julia;
	while (++y < WIN_Y && f)
	{
		x = -1;
		while (++x < WIN_X)
			f(x, y, e, 0);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_string_put(e->mlx, e->win, 0, 2, 0xffffff, "Fractale de ");
	mlx_string_put(e->mlx, e->win, 125, 2, 0xffffff, e->fractal);
	mlx_string_put(e->mlx, e->win, 0, 17, 0xffffff,
			"Profondeur actuelle : ");
	mlx_string_put(e->mlx, e->win, 220, 17, 0xffffff, ft_itoa(e->depth));
}

int		choose_color(double i, t_env *e)
{
	if (i < e->depth)
		return (0x000000 + i * 0x101010);
	return (0x000000);
}

void	mandelbrot(int x, int y, t_env *e, int i)
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
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = (z_i + z_i) * tmp + c_i;
		i++;
	}
	pixel_put(e, (int)x, (int)y, choose_color(i, e));
}

void	julia(int x, int y, t_env *e, int i)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
	double	tmp2;

	i = 0;
	c_r = 0;
	c_i = 0;
	z_r = (x - WIN_X / 2) / e->zoom + e->place_x;
	z_i = (y - WIN_Y / 2) / e->zoom + e->place_y;
	while (z_r * z_r + z_i * z_i < 4 && i < e->depth)
	{
		tmp = z_r;
		tmp2 = z_i;
		z_r = z_r * z_r - z_i * z_i + e->r_julia;
		z_i = (tmp + tmp) * tmp2 + e->i_julia;
		i++;
	}
	pixel_put(e, (int)x, (int)y, choose_color(i, e));
}
