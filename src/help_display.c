/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 22:47:12 by telain            #+#    #+#             */
/*   Updated: 2016/06/23 23:20:07 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		help_display(void)
{
	ft_putstr("\e[31m-------------------------------------------------\e[0m\n");
	ft_putstr("\nAvailabe fractals :\n\n");
	ft_putstr("\t\e[32m-\e[0m Mandelbrot\n");
	ft_putstr("\t\e[32m-\e[0m Julia\n");
	ft_putstr("\t\e[32m-\e[0m Fisheye (Modified Julia)\n");
	ft_putstr("\t\e[32m-\e[0m Burningship\n\n");
	ft_putstr("\e[31m-------------------------------------------------\e[0m\n");
}
