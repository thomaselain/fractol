/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 22:47:12 by telain            #+#    #+#             */
/*   Updated: 2016/06/24 17:05:27 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		help_display(void)
{
	ft_putendl("\e[31m-------------------------------------------------------");
	ft_putstr("\n\t\t\e[0mAvailabe fractals :\n\n");
	ft_putstr("\e[32m-\e[0m Mandelbrot\n");
	ft_putstr("\e[32m-\e[0m Julia\n");
	ft_putstr("\e[32m-\e[0m Fisheye (Modified Julia)\n");
	ft_putstr("\e[32m-\e[0m Burningship\n\n\n\n");
	ft_putstr("\t\tAvailabe inputs :\n\n");
	ft_putstr("\e[32m-\e[0m Change color with 'c' (");
	ft_putstr("\e[31mred\e[0m/\e[32mgreen\e[0m/\e[34mblue\e[0m/white)\n");
	ft_putstr("\e[32m-\e[0m Enable/Disable julia sets with 'p'\n");
	ft_putstr("\e[32m-\e[0m Mouse scroll up/down : zoom in/out\n");
	ft_putstr("\e[32m-\e[0m Move mouse to change julia sets\n");
	ft_putstr("\e[32m-\e[0m Left/Right clic : More/less depth\n\n");
	ft_putendl("\e[31m-------------------------------------------------------");
}
