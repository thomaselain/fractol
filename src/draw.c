/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:38:13 by telain            #+#    #+#             */
/*   Updated: 2016/06/23 23:03:47 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		refresh(void *e)
{
	draw_window(e);
	return (0);
}

void	draw_window(t_env *e)
{
	int		x;
	int		y;
	void	(*f)(int x, int y, t_env *e, int i);

	y = -1;
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sl), &(e->endi));
	if (ft_strcmp(e->fractal, "mandelbrot") == 0)
		(f) = &mandelbrot;
	else if (ft_strcmp(e->fractal, "julia") == 0)
		(f) = &julia;
	else if (ft_strcmp(e->fractal, "fisheye") == 0)
		(f) = &fisheye;
	else if (ft_strcmp(e->fractal, "burningship") == 0)
		(f) = &burningship;
	while (++y < WIN_Y && f)
	{
		x = -1;
		while (++x < WIN_X)
			f(x, y, e, 0);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_string_put(e->mlx, e->win, 0, 2, 0xffffff, "Fractale\t\t: ");
	mlx_string_put(e->mlx, e->win, 110, 2, 0xffffff, e->fractal);
	mlx_string_put(e->mlx, e->win, 0, 17, 0xffffff, "Profondeur\t\t: ");
	mlx_string_put(e->mlx, e->win, 125, 17, 0xffffff, ft_itoa(e->depth));
}

void	pixel_put(t_env *e, int x, int y, int color)
{
	unsigned int	new_color;

	new_color = mlx_get_color_value(e->mlx, color);
	e->data[y * e->sl + x * e->bpp / 8] = (new_color & 0xff);
	e->data[y * e->sl + x * e->bpp / 8 + 1] = (new_color & 0xff00) >> 8;
	e->data[y * e->sl + x * e->bpp / 8 + 2] = (new_color & 0xff0000) >> 16;
}
