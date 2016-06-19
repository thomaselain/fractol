/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:05:10 by telain            #+#    #+#             */
/*   Updated: 2016/06/19 01:49:11 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	choose_fractal(t_env *e)
{
	if (ft_strcmp(e->fractal, "julia") == 0)
		e->fractal = "mandelbrot";
	else if (ft_strcmp(e->fractal, "mandelbrot") == 0)
		e->fractal = "julia";
	e->zoom = WIN_X / 4;
	e->depth = 10;
}

void	do_input(t_env *e, int key)
{
	if (key == 53)
		exit(0);
	(key == 36) ? choose_fractal(e) : key;
	(key == 123) ? e->place_x -= (double)WIN_X / e->zoom / 8 : key;
	(key == 124) ? e->place_x += (double)WIN_X / e->zoom / 8 : key;
	(key == 125) ? e->place_y += (double)WIN_Y / e->zoom / 8 : key;
	(key == 126) ? e->place_y -= (double)WIN_Y / e->zoom / 8 : key;
	(key == 69) ? e->depth++ : key;
	(key == 78) ? e->depth-- : key;
}
