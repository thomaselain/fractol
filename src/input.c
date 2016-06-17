/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:05:10 by telain            #+#    #+#             */
/*   Updated: 2016/06/17 18:54:02 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		write_zoom(void)
{
	char	*line;

	get_next_line(0, &line);
	return (ft_atoi(line));
}

void	do_input(t_env *e, int key)
{
	if (key == 53)
		exit(0);
	(key == 36) ? e->depth = write_zoom() : key;
	(key == 36) ? e->zoom = e->zoom : key;
	(key == 123) ? e->place_x -= (double)WIN_X / e->zoom / 8 : key;
	(key == 124) ? e->place_x += (double)WIN_X / e->zoom / 8 : key;
	(key == 125) ? e->place_y += (double)WIN_Y / e->zoom / 8 : key;
	(key == 126) ? e->place_y -= (double)WIN_Y / e->zoom / 8 : key;
	(key == 69) ? e->depth++ : key;
	(key == 78) ? e->depth-- : key;
}
