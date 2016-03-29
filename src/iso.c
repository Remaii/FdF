/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Remaii <Remaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:08:29 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/29 14:41:33 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void				img_put(t_mlx *f, int x, int y, int color)
{
	char			*data;
	unsigned int	val;

	data = f->idata;
	val = mlx_get_color_value(f->mlx, color);
	if (x > 0 && x < f->width && y > 0 && y < f->heigt)
		ft_memcpy(data + y * f->size + x * (f->bpp / 8), &val, 3);
}

void				vline(t_mlx *fdf, t_pts *pt1, t_pts *pt2, int color)
{
	int				i;

	i = pt1->y;
	while (i <= pt2->y)
	{
		img_put(fdf, pt1->x + ((pt2->x - pt1->x) * (i - pt1->y))\
				/ (pt2->y - pt1->y), i, color);
		i++;
	}
}

void				hline(t_mlx *fdf, t_pts *pt1, t_pts *pt2, int color)
{
	int				i;

	i = pt1->x;
	while (i <= pt2->x)
	{
		img_put(fdf, i, pt1->y + ((pt2->y - pt1->y) * (i - pt1->x))\
				/ (pt2->x - pt1->x), color);
		i++;
	}
}
