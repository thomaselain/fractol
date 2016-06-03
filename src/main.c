/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:37:22 by telain            #+#    #+#             */
/*   Updated: 2016/06/01 17:47:56 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		find_key(int key, void *e)
{
	if (key == 53 || key == 125 || key == 126 || key == 69 || key == 78)
	{
		do_input(e, key);
	}
	draw(e);
	return (key);
}

void	new_env(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "fractol_42");
	e->depth = 0;
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
	{
		ft_putstr("Usage : ./fractol <\e[32mdepth\e[0m>\n");
		return (0);
	}
	new_env(&e);
	e.depth = ft_atoi(av[1]);
	e.zoom_x = WIN_X;
	e.zoom_y = WIN_Y;
	mlx_key_hook(e.win, find_key, &e);
	mlx_loop(e.mlx);
	return (0);
}
