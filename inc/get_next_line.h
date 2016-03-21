/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 22:59:56 by rthidet           #+#    #+#             */
/*   Updated: 2016/02/08 18:38:20 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8
# define MAX_FD 256
# include "libft.h"
# include <fcntl.h>

typedef struct	s_gnl
{
	char		*line[MAX_FD + 1];
	char		*buffer;
	int			nb;
	char		*tmp;
}				t_gnl;

int		get_next_line(int const fd, char **line);

#endif
