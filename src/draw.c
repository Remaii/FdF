/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 11:53:31 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/23 09:58:34 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>
/*
void			draw_img(t_mlx *fdf, int x, int y, int color)
{
	fdf->idata[y * fdf->heigt + x] = color;
}

void			draw_hline(t_mlx *fdf, int x, int y, int d_x)
{
	int i;
	int dst;

	i = x;
	dst = x * d_x;
	while (i < dst)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, i, y, wcolor(fdf, fdf->map[x][y]));
		i++;
	}
}*/

int				test(t_mlx *fdf)
{
	int i;
	int j;
	int x;
	int y;
	int xj;
	int yi;

	i = 0;
	y = 0;
	xj = (fdf->width / fdf->x);
	yi = (fdf->heigt / fdf->y);
//	if (fdf->test == 1)
//	{
//		mlx_clear_window(fdf->mlx, fdf->win);
//		fdf->test = 0;
//	}
	while (i <= fdf->width)
	{
		j = 0;
		x = 0;
		while (j <= fdf->heigt)
		{
			//if (fdf->test == 0)
			//{
				iso(fdf, i, j, fdf->map[y][x]);
			//	toiso(fdf, i, j, fdf->relief, fdf->map[y][x]);
			//}
			//else
			//	toiso(fdf, i, j, fdf->relief, fdf->map[y][x]);
			j += xj;
			x++;
		}
		i += yi;
		y++;
	}
	fdf->test = 1;
	return (0);
}
