/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:37:22 by telain            #+#    #+#             */
/*   Updated: 2016/06/30 18:35:55 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		parse_arg(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr("\nUsage: ./fractol <\e[32mFractal_name");
		ft_putstr(" \e[0m/ \e[31mhelp\e[0m>\n\n");
		return (0);
	}
	else if (ft_strcmp(av[1], "help") == 0)
	{
		help_display();
		return (0);
	}
	else if (ft_strcmp("julia", av[1]) && ft_strcmp("mandelbrot", av[1]) &&
			ft_strcmp("fisheye", av[1]) && ft_strcmp("burningship", av[1]))
	{
		ft_putendl("\n\n\e[31m/!\\\e[0m   Invalid fractal   \e[31m/!\\\e[0m\n");
		return (0);
	}
	return (1);
}

int		find_mouse(int x, int y, void *e)
{
	if (x >= 0 && y >= 0 && x <= WIN_X && y <= WIN_Y)
		change_input(e, x, y, 0);
	return (0);
}

void	new_env(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Fractol_42");
	e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->depth = 10;
	e->zoom = WIN_X / 4;
	e->place_x = 0;
	e->place_y = 0;
	e->param = 0;
	e->palette = 0;
}

int		main(int ac, char **av)
{
	t_env	e;

	if (!parse_arg(ac, av))
		return (0);
	new_env(&e);
	e.fractal = av[1];
	mlx_hook(e.win, 1, (1 << 11), button_pressed, &e);
	mlx_hook(e.win, 2, (1 << 11), button_pressed, &e);
	mlx_hook(e.win, 4, (1 << 11), button_pressed, &e);
	mlx_hook(e.win, 5, (1 << 12), button_pressed, &e);
	mlx_hook(e.win, 6, (1L << 6), find_mouse, &e);
	mlx_hook(e.win, 2, 0, expose_find_key, &e);
	mlx_key_hook(e.win, find_key, &e);
	mlx_loop_hook(e.mlx, refresh, &e);
	mlx_loop(e.mlx);
	return (0);
}

int		button_pressed(int button, int x, int y, void *e)
{
	if (x >= 0 && y >= 0 && x <= WIN_X && y <= WIN_Y)
		change_input(e, x, y, button);
	return (0);
}
