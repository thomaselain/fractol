/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:38:02 by telain            #+#    #+#             */
/*   Updated: 2015/12/02 17:48:04 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dst, const char *str, size_t n)
{
	size_t		i;

	i = 0;
	while (str[i] && i < n)
	{
		dst[i] = str[i];
		i++;
	}
	while (i < n)
		dst[i++] = '\0';
	return (dst);
}
