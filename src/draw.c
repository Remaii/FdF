/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 11:53:31 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/28 21:52:26 by rthidet          ###   ########.fr       */
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

//screen.x = (map.x - map.y) * TILE_WIDTH_HALF; 
//screen.y = (+ map.x map.y) * TILE_HEIGHT_HALF;

/*
int				test(t_mlx *f)
{
	int x;
	int y;
	t_diff d;

	d.xj
}
*/
int				test(t_mlx *fdf)
{
	float i;
	float j;
	t_diff d;

	i = 0;
	d.y = 0;
	d.xj = fdf->width / fdf->x;
	d.yi = fdf->heigt / fdf->y;
//	if (fdf->test == 1)
//	{
//		mlx_clear_window(fdf->mlx, fdf->win);
//		fdf->test = 0;
//	}
	while (d.y <= fdf->y)
	{
		j = 0;
		d.x = 0;
		while (d.x <= fdf->x)
		{
			//if (fdf->test == 0)
			//{
				iso(fdf, &d, i, j, fdf->map[d.y][d.x]);
			//printf("i= %f j= %f xj=%f yi= %f x=%d y= %d\n", i, j, d.xj, d.yi, d.x, d.y);
			//	toiso(fdf, i, j, fdf->relief, fdf->map[y][x]);
			//}
			//else
			//	toiso(fdf, i, j, fdf->relief, fdf->map[y][x]);
			j += d.xj;
			d.x++;
		}
		i += d.yi;
		d.y++;
	}
	//fdf->test = 1;
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, fdf->xoff, fdf->yoff);
	return (0);
}
