/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:52:46 by cchicote          #+#    #+#             */
/*   Updated: 2016/03/05 16:02:43 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include "../includes/libft.h"
# include <stdio.h>
# include <fcntl.h>
# define BUFF_SIZE 1 

typedef struct	s_gnl
{
	char		buf[BUFF_SIZE + 1];
	char		*str;
	int			s;
	int			end;
}				t_gnl;

int				get_next_line(int const fd, char **line);

#endif
