/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:56:22 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/22 13:18:08 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_mlx			init_mandelbrot(t_mlx pt)
{
	pt.x1 = -2.1;
	pt.y1 = -1.2;
	pt.x2 = 0.6;
	pt.y2 = 1.2;
	pt.it = 50;
	pt.k = 0;
	pt.l = 0;
	pt.zoom = 400;
	pt.img_x = (pt.x2 - pt.x1) * pt.zoom;
	pt.img_y = (pt.y2 - pt.y1) * pt.zoom;
	return (pt);
}

void			mandelbrot(t_mlx f)
{
	f.x = 0;
	while (f.x < f.width)
	{
		f.y = 0;
		while (f.y < f.height)
		{
			f.cr = f.x / f.zoom + f.x1;
			f.ci = f.y / f.zoom + f.y1;
			f.zr = 0;
			f.zi = 0;
			f.i = 0;
			while (f.zr * f.zr + f.zi * f.zi < 4 && f.i < f.it)
			{
				f.tmp = f.zr;
				f.zr = f.zr * f.zr - f.zi * f.zi + f.cr;
				f.zi = 2 * f.zi * f.tmp + f.ci;
				f.i++;
			}
			if (f.i == f.it)
				f.map[f.y][f.x] = 0xFFFFFF;
			else
				f.map[f.y][f.x] = 0x000000;
			f.y++;
		}
		f.x++;
	}
}






