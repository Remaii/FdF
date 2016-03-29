/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Remaii <Remaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 11:53:31 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/29 12:25:17 by Remaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

void draw_line(t_mlx *f, t_pts *pt1, t_pts *pt2, int color)
{
	if (abs(pt1->x - pt2->x) > abs(pt1->y - pt2->y))
	{
		if (pt1->x < pt2->x)
			hline(f, pt1, pt2, color);
		else
			hline(f, pt2, pt1,color);
	}
	else
	{
		if (pt1->y < pt2->y)
			vline(f, pt1, pt2, color);
		else
			vline(f, pt2, pt1, color);
	}
}

t_pts		get_pt(int x, int y, int z)
{
	t_pts pt;

	pt.x = x;
	pt.y = y;
	pt.z = z;
	return (pt);
}

void make_iso(t_pts *pt, t_mlx *f)
{
	t_pts tmp;

	tmp.x = pt->x;
	tmp.y = pt->y;
	tmp.z = pt->z;
	pt->x = tmp.x * 2 - tmp.y * 2;
	pt->y = tmp.x + tmp.y - tmp.z * f->relief;
	pt->x *= f->zoom;
	pt->y *= f->zoom;
	pt->x += f->xoff;
	pt->y += f->yoff;
}

void draw_square(t_mlx *f, t_pts pt1, t_pts pt2, t_pts pt3, t_pts pt4)
{
	make_iso(&pt1, f);
	make_iso(&pt2, f);
	make_iso(&pt3, f);
	make_iso(&pt4, f);
	draw_line(f, &pt1, &pt2, wcolor(f, (pt1.z > pt2.z) ? pt1.z : pt2.z));
	draw_line(f, &pt1, &pt3, wcolor(f, (pt1.z > pt3.z) ? pt1.z : pt3.z));
	//if(pt4.x == f->x || pt4.y == f->y)
	//{
		draw_line(f, &pt3, &pt4, wcolor(f, (pt3.z > pt4.z) ? pt3.z : pt4.z));
		draw_line(f, &pt2, &pt4, wcolor(f, (pt2.z > pt4.z) ? pt2.z : pt4.z));
	//}
}

int			draw(t_mlx *f)
{
	int		x;
	int		y;

	x = 0;
	if (f->draw == 1)
		new_img(f);
	while (x < f->x - 1)
	{
		y = 0;
		while (y <= f->y - 1)
		{
//			printf("x=%d y=%d\n", x , y);
			draw_square(f, get_pt(x, y, f->map[x][y]),\
						   get_pt(x + 1, y, f->map[x + 1][y]),\
						   get_pt(x, y + 1, f->map[x][y + 1]),\
						   get_pt(x + 1, y + 1, f->map[x + 1][y + 1]));
			y++;
		}
		x++;
	}
	f->draw = 1;
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
