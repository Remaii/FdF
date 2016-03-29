/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Remaii <Remaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:08:29 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/29 11:37:56 by Remaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		img_put(t_mlx *f, int x, int y, int color)
{
	char *data;
	unsigned int val;

	data = f->idata;
	val = mlx_get_color_value(f->mlx, color);
	if (x > 0 && x < f->width && y > 0 && y < f->heigt)
		ft_memcpy(data + y * f->size + x * (f->bpp / 8), &val, 3);
}

void		vline(t_mlx *fdf, t_pts *pt1, t_pts *pt2, int color)//int x, int y, int color, int d_y)
{
	int i;

	i = pt1->y;
	while (i <= pt2->y)
	{
		img_put(fdf, pt1->x + ((pt2->x - pt1->x) * (i - pt1->y)) / (pt2->y - pt1->y), i, color);
		i++;
	}
}

void		hline(t_mlx *fdf, t_pts *pt1, t_pts *pt2, int color)//int x, int y, int color, int d_x)
{
	int i;

	i = pt1->x;
	while (i <= pt2->x)
	{
		img_put(fdf, i, pt1->y + ((pt2->y - pt1->y) * (i - pt1->x)) / (pt2->x - pt1->x), color);
		i++;
	}
}
/*
void			toiso(t_mlx *fdf, t_3d *pt, double ct1)//int x, int y, double ct1, int z)
{
	double c;
	int i;
	int j;

	c = 0.000;
	while (c <= ct1)
	{
		printf("c= %f to c= %f\n", c, ct1);
		i = pt->x1 + c * pt->z1;
		j = pt->y1 + (c/2) * pt->z1;
		img_put(fdf, i, j, wcolor(fdf, pt->z1));
		c += 0.1;
	}
}*/

/*
void			iso(t_mlx *fdf, t_diff *d, int x, int y, int z)
{
//	printf("x= %d y= %d z= %d d.xj= %f d.yi= %f fdf.x= %d fdf.y= %d d.x= %d d.y= %d \n", x, y, z, d->xj, d->yi, fdf->x, fdf->y, d->x, d->y);
	if (((x == 0 || (x + d->xj) > fdf->width) && y < fdf->heigt))
	{
		printf("vline x=%d, y=%d, color=%d, decal=%f\n", x, y, z, d->xj);
		vline(fdf, x, y, wcolor(fdf, z), d->xj);
	}
	if (y == fdf->heigt && x != fdf->width)
	{
		printf("hline x=%d, y=%d, color=%d, decal=%f\n", x, y, wcolor(fdf, z), d->yi);
		hline(fdf, x, y, wcolor(fdf, z), d->yi);
	}
	else if (x < fdf->width && y < fdf->heigt)
	{
		printf("1 hline x=%d, y=%d, color=%d, yi=%f\n", x, y, z, d->yi);
		printf("2 vline x=%d, y=%d, color=%d, xj=%f\n", x, y, z, d->xj);
//		hline(fdf, x, y, wcolor(fdf, z), d->yi);
//		vline(fdf, x, y, wcolor(fdf, z), d->xj);
//	}
//	toiso(fdf, x, y, fdf->relief, z);
	int a;
	a = fdf->x;
}*/
/*
int		main()
{
	int z;
	t_mlx fdf;

	fdf.y = 0;
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 850, 650, "TEST");
	while (fdf.y <= 600)
	{
		z = 30;
		fdf.x = 0;
		while (fdf.x <= 800)
		{
			iso(&fdf, fdf.x, fdf.y, z);
			fdf.x += 80;
		}
		fdf.y += 60;
	}
	mlx_loop(fdf.mlx);
	return (0);
}*/
