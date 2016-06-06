/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:37:22 by telain            #+#    #+#             */
/*   Updated: 2016/06/06 22:21:56 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		find_key(int key, void *e)
{
	if (key == 53 || key == 125 || key == 126 || key == 69 || key == 78 ||
			key == 123 || key == 124 || key == 1225 || key == 126)
	{
		do_input(e, key);
		draw(e);
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

void	new_env(t_env *e, int depth)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Fractol_42");
	e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->depth = depth;
	e->zoom_x = 10;
	e->zoom_y = 10;
	e->x = 0;
	e->y = 0;
}

int		main(int ac, char **av)
{
	t_env	e;
	int		x;
	int		y;

	y = 0;
	x = 0;
	if (ac != 2)
	{
		ft_putstr("Usage : ./fractol <\e[32mdepth\e[0m>\n");
		return (0);
	}
	new_env(&e, ft_atoi(av[1]));
	mlx_key_hook(e.win, find_key, &e);
	mlx_loop(e.mlx);
	return (0);
}
