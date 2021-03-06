/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 19:49:50 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/24 14:21:55 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_pts		*n_pts(int x, int y, int z)
{
	t_pts	*pts;

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
	t_list	*tmp;
	t_pts	*pt;

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
			map[(int)pt->x][(int)pt->y] = pt->z;
		tmp = tmp->next;
	}
	fdf->map = map;
	fdf->zoom = 500 / (x + y);
	fdf->xoff = x * fdf->zoom * 3;
	fdf->yoff = y * fdf->zoom * 3;
	fdf->relief = 0.2;
}

void		parsemap(t_mlx *fdf, int fd)
{
	int		i;
	int		j;
	t_list	*pts;
	char	*line;
	char	**lines;

	i = 0;
	while (get_next_line(fd, &line))
	{
		lines = ft_strsplit(line, ' ');
		j = 0;
		while (lines[j] != NULL)
		{
			ft_lstadd(&pts, ft_lstnew(n_pts(j, i, ft_atoi(lines[j])),\
													sizeof(t_pts)));
			j++;
		}
		i++;
	}
	fdf->x = j;
	fdf->y = i;
	lst_map(pts, fdf, j, i);
}
