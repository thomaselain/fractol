/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:37:22 by telain            #+#    #+#             */
/*   Updated: 2016/06/17 19:11:58 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		refresh(void *e)
{
	draw(e);
	return (0);
}

void	change_input(t_env *e, int x, int y, int fct)
{
	if (fct == 0)
	{
		e->x = x;
		e->y = y;
	}
	else if (fct == 1)
	{
		e->zoom *= 1.5;
		e->place_x -= ((double)WIN_X / 2 - x) / e->zoom;
		e->place_y -= ((double)WIN_Y / 2 - y) / e->zoom;
	}
	else if (fct == 2)
	{
		e->zoom /= 1.5;
	}
}

int		button_pressed(int button, int x, int y, void *e)
{
	if (x >= 0 && y >= 0 && x <= WIN_X && y <= WIN_Y)
		change_input(e, x, y, button);
	return (0);
}

int		find_mouse(int x, int y, void *e)
{
	if (x >= 0 && y >= 0 && x <= WIN_X && y <= WIN_Y)
		change_input(e, x, y, 0);
	return (0);
}

int		find_key(int key, void *e)
{
	if (key == 53 || key == 125 || key == 126 || key == 69 || key == 78 ||
			key == 123 || key == 124 || key == 13 || key == 1 || key == 36)
	{
		do_input(e, key);
	}

	return (key);
}

void	pixel_put(t_env *e, int x, int y, int color)
{
	unsigned int	new_color;

	new_color = mlx_get_color_value(e->mlx, color);
	e->data[y * e->sl + x * e->bpp / 8] = (new_color & 0xff);
	e->data[y * e->sl + x * e->bpp / 8 + 1] = (new_color & 0xff00) >> 8;
	e->data[y * e->sl + x * e->bpp / 8 + 2] = (new_color & 0xff0000) >> 16;
}

void	new_env(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Fractol_42");
	e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->depth = 5;
	e->zoom = WIN_X / 4;
	e->place_x = 0;
	e->place_y = 0;
}

int		main(int ac, char **av)
{
	t_env	e;
	int		x;
	int		y;

	y = 0;
	x = 0;
	if (ac != 1)
	{
		if (av)
			;
		ft_putstr("Usage : ./fractol\n");
		return (0);
	}
	new_env(&e);
	mlx_key_hook(e.win, find_key, &e);
	mlx_mouse_hook(e.win, button_pressed, &e);
	mlx_hook(e.win, 6, (1L << 6), find_mouse, &e);
	mlx_loop_hook(e.mlx, refresh, &e);
	mlx_loop(e.mlx);
	return (0);
}
