/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 19:49:50 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/23 23:03:30 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

t_pts		*n_pts(int x, int y, int z)
{
	t_pts *pts;

	pts = (t_pts *)ft_memalloc(sizeof(t_pts));
	pts->x = x;
	pts->y = y;
	pts->z = z;
	return (pts);
}

void		lst_map(t_list *pts, t_mlx *fdf, int x, int y)
{
	int		i;
	int		**map;
	t_list *tmp;
	t_pts *pt;

	i = 0;
	tmp = pts;
	map = (int **)ft_memalloc(sizeof(int *) * x);
	while (i < x)
	{
		map[i] = (int *)ft_memalloc(sizeof(int *) * y);
		i++;
	}
	while (tmp)
	{
		pt = tmp->content;
		if (pt->x < x && pt->y < y)
			map[pt->x][pt->y] = pt->z;
		tmp = tmp->next;
	}
	fdf->map = map;
	fdf->zoom = 100 / (x + y);
	fdf->xoff = x * fdf->zoom * 3;
	fdf->yoff = y * fdf->zoom * 2;
	fdf->relief = 1;
//	status(fdf);
}

void		parsemap(t_mlx *fdf, int fd)
{
	int		i;
	int		j;
	t_list	*pts;
	char	*line;
	char	**lines;

	i = 0;
//	printf("debut\n");
	while (get_next_line(fd, &line))
	{
		//printf("line = %s\n", line);
		lines = ft_strsplit(line, ' ');
		j = 0;
		while (lines[j] != NULL)
		{
			set_color(fdf, ft_atoi(lines[j]));
//			iso(fdf, j, i, ft_atoi(lines[j]));
			ft_lstadd(&pts, ft_lstnew(n_pts(j, i, ft_atoi(lines[j])),\
													sizeof(t_pts)));
			j++;
		}
		i++;
	}
	fdf->x = j;
	fdf->y = i;
//	printf("fin = fdf.x %d fdf.y %d\n", fdf->x, fdf->y);
//	printf("fin = fdf.xoff %d fdf.yoff %d\n", fdf->xoff, fdf->yoff);
	lst_map(pts, fdf, j, i);
//	lol(pts);
//test(fdf->map, fdf);
//	error(10);
}
