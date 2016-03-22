/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 11:53:31 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/22 15:58:56 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

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
}

void			test(int **map, t_mlx *fdf)
{
	int i;
	int j;
	int xj;
	int yi;

	i = 1;
	xj = (fdf->width / fdf->x);
	yi = (fdf->heigt / fdf->y);
	while (i <= (fdf->y * 2))
	{
		j = 1;
		while (j <= fdf->x)
		{
			draw_img(fdf, i, j, wcolor(fdf, fdf->map[i][j]));
			//img_put_pixel(fdf, i, j, wcolor(fdf, map[i][j]));
	//		mlx_pixel_put(fdf->mlx, fdf->win, (xj * i), (yi * j), wcolor(fdf, map[i][j]));
			printf("%d ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
		if (!map[i])
			break ;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
