/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:08:29 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/23 10:00:23 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		vline(t_mlx *fdf, int x, int y, int color, int d_y)
{
	int i;

	i = y;
	while (i <= (y + d_y))
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x, i, color);
		i++;
	}
}

void		hline(t_mlx *fdf, int x, int y, int color, int d_x)
{
	int i;

	i = x;
	while (i <= (x + d_x))
	{
		mlx_pixel_put(fdf->mlx, fdf->win, i, y, color);
		i++;
	}
}

void			toiso(t_mlx *fdf, int x, int y, double ct1, int z)
{
	double c;
	int i;
	int j;

	c = 0.000;
	while (c <= ct1)
	{
		i = x + c * z;
		j = y + (c/2) * z;
		mlx_pixel_put(fdf->mlx, fdf->win, i, j, wcolor(fdf, z));
		c += 0.001;
	}
}


void			iso(t_mlx *fdf, int x, int y, int z)
{
	int w;
	int h;

	w = (fdf->width / fdf->xoff);
	h = (fdf->heigt / fdf->yoff);
	if (x == fdf->width && y != fdf->heigt)
		vline(fdf, x, y, wcolor(fdf, z), h);
	if (y == fdf->heigt && x != fdf->width)
		hline(fdf, x, y, wcolor(fdf, z), w);
	else if (x < (fdf->width - w) && y < (fdf->heigt - h))
	{
		hline(fdf, x, y, wcolor(fdf, z), (fdf->heigt - h));
		vline(fdf, x, y, wcolor(fdf, z), (fdf->width - w));
	}
	toiso(fdf, x, y, fdf->relief, z);
}
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
