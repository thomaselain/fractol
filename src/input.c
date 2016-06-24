/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:05:10 by telain            #+#    #+#             */
/*   Updated: 2016/06/24 16:36:42 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_palette(t_env *e)
{
	if (e->palette < 3)
		e->palette++;
	else
		e->palette = 0;
}

void	choose_fractal(t_env *e)
{
	if (ft_strcmp(e->fractal, "julia") == 0)
		e->fractal = "mandelbrot";
	else if (ft_strcmp(e->fractal, "mandelbrot") == 0)
		e->fractal = "fisheye";
	else if (ft_strcmp(e->fractal, "fisheye") == 0)
		e->fractal = "burningship";
	else if (ft_strcmp(e->fractal, "burningship") == 0)
		e->fractal = "julia";
	e->param_r = 0;
	e->param_i = 0;
	e->param = 0;
	e->zoom = WIN_X / 4;
	e->depth = 10;
}

void	do_input(t_env *e, int key)
{
	if (key == 53)
		exit(0);
	if (key == KEY_C)
		change_palette(e);
	if (key == KEY_P && e->param == 0)
		e->param = 1;
	else if (key == KEY_P)
		e->param = 0;
	(key == 36) ? choose_fractal(e) : key;
	(key == 123) ? e->place_x -= (double)WIN_X / e->zoom / 8 : key;
	(key == 124) ? e->place_x += (double)WIN_X / e->zoom / 8 : key;
	(key == 125) ? e->place_y += (double)WIN_Y / e->zoom / 8 : key;
	(key == 126) ? e->place_y -= (double)WIN_Y / e->zoom / 8 : key;
	(key == 69) ? e->depth++ : key;
	(key == 78) ? e->depth-- : key;
}

void	change_input(t_env *e, int x, int y, int fct)
{
	if (fct == 0 && e->param == 1)
	{
		e->x = x;
		e->y = y;
		e->param_r = (x - (double)WIN_X / 2) / 200;
		e->param_i = (y - (double)WIN_Y / 2) / 200;
	}
	else if (fct == 1)
		e->depth++;
	else if (fct == 2)
		e->depth--;
	else if (fct == 4)
	{
		e->zoom *= 1.5;
		e->place_x -= ((double)WIN_X / 2 - x) / e->zoom / 2;
		e->place_y -= ((double)WIN_Y / 2 - y) / e->zoom / 2;
	}
	else if (fct == 5)
		e->zoom /= 1.5;
}

int		find_key(int key, void *e)
{
	if (key == 53 || key == 125 || key == 126 || key == 69 || key == 78 ||
			key == 123 || key == 124 || key == 13 || key == 1 || key == 36
			|| key == KEY_P || key == KEY_C)
	{
		do_input(e, key);
	}
	return (key);
}
