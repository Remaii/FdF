/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Remaii <Remaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:22:56 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/29 15:11:18 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

void	new_img(t_mlx *f)
{
	mlx_destroy_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, f->width, f->heigt);
	f->idata = mlx_get_data_addr(f->img, &(f->bpp), &(f->size), &(f->end));
}

void	ft_stop(t_mlx *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

/*
** 53 = ESC, 123 = fleche gauche, 124 = fleche droite, 125 = fleche haut,
** 126 = fleche bas, 13 = W, 1 = S, 12 = Q, 0 = A, 15 = R
*/

int		ft_key(int keycode, t_mlx *fdf)
{
	if (keycode == 53)
		ft_stop(fdf);
	else if (keycode == 123)
		fdf->xoff -= 20;
	else if (keycode == 124)
		fdf->xoff += 20;
	else if (keycode == 125)
		fdf->yoff += 20;
	else if (keycode == 126)
		fdf->yoff -= 20;
	else if (keycode == 13)
		fdf->zoom *= 1.05;
	else if (keycode == 1)
		fdf->zoom /= 1.05;
	else if (keycode == 12)
		fdf->relief += 0.05;
	else if (keycode == 0)
		fdf->relief -= 0.05;
	else if (keycode == 15)
	{
		fdf->xoff = ((fdf->width / 2) - 100);
		fdf->yoff = ((fdf->heigt / 2) - 130);
	}
	draw(fdf);
	return (0);
}
