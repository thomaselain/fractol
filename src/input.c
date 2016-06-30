/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:05:10 by telain            #+#    #+#             */
/*   Updated: 2016/06/30 18:38:13 by telain           ###   ########.fr       */
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
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_C)
		change_palette(e);
	if (key == KEY_P && e->param == 0)
		e->param = 1;
	else if (key == KEY_P)
		e->param = 0;
	(key == KEY_ENTER) ? choose_fractal(e) : key;
	(key == KEY_LEFT) ? e->place_x -= (double)WIN_X / e->zoom / 8 : key;
	(key == KEY_RIGHT) ? e->place_x += (double)WIN_X / e->zoom / 8 : key;
	(key == KEY_DOWN) ? e->place_y += (double)WIN_Y / e->zoom / 8 : key;
	(key == KEY_UP) ? e->place_y -= (double)WIN_Y / e->zoom / 8 : key;
	(key == KEY_EQUAL) ? e->depth++ : key;
	(key == KEY_MINUS) ? e->depth-- : key;
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
	if (key == KEY_P || key == KEY_C || key == KEY_ENTER || key == KEY_ESC)
		do_input(e, key);
	return (key);
}

int		expose_find_key(int key, void *e)
{
	if (key == KEY_UP || key == KEY_LEFT || key == KEY_DOWN || key == KEY_RIGHT
			|| key == KEY_MINUS || key == KEY_EQUAL)
		do_input(e, key);
	return (key);
}
