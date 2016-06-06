/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:05:10 by telain            #+#    #+#             */
/*   Updated: 2016/06/06 22:15:49 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	do_input(t_env *e, int key)
{
	if (key == 53)
		exit(0);
	(key == 126) ? e->zoom_x += 300 : key;
	(key == 126) ? e->zoom_y += 300 : key;
	(key == 125) ? e->zoom_x -= 300 : key;
	(key == 125) ? e->zoom_y -= 300 : key;
	(key == 69) ? e->depth++ : key;
	(key == 78) ? e->depth-- : key;
	(key == 126) ? e->y-- : key;
	(key == 124) ? e->x++ : key;
	(key == 125) ? e->y++ : key;
	(key == 123) ? e->x-- : key;
}
