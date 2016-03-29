/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Remaii <Remaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:22:56 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/29 12:25:07 by Remaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

void	status(t_mlx *fdf)
{
	printf("x= %d y= %d width= %d heigt= %d bpp= %d size= %d end= %d\n", fdf->x, fdf->y, fdf->width, fdf->heigt, fdf->bpp, fdf->size, fdf->end);
	printf("xoff= %d yoff= %d max= %d min= %d idata= %s zoom= %f relief= %f\n", fdf->xoff, fdf->yoff, fdf->max, fdf->min, fdf->idata, fdf->zoom, fdf->relief);
}

void			new_img(t_mlx *f)
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

int		ft_key(int keycode, t_mlx *fdf)
{
	if (keycode == 53)/* ESC */
		ft_stop(fdf);
	else if (keycode == 123)/* fleche gauche */
		fdf->xoff -= 20;
	else if (keycode == 124)/* fleche droite */
		fdf->xoff += 20;
	else if (keycode == 125)/* fleche haut */
		fdf->yoff += 20;
	else if (keycode == 126)/* fleche bas */
		fdf->yoff -= 20;
	else if (keycode == 13)/* W */
		fdf->zoom *= 1.05;
	else if (keycode == 1)/* S */
		fdf->zoom /= 1.05;
	else if (keycode == 12)/* Q */
		fdf->relief *= 1.05;
	else if (keycode == 0)/* A */
		fdf->relief /= 1.05;
	else if (keycode == 46)/* M */
	{
		status(fdf);
		return (0);
	}
	else if (keycode == 15)/* R */
	{
		fdf->xoff = ((fdf->width / 2) - 100);
		fdf->yoff = ((fdf->heigt / 2) - 130);
	}
	else
		ft_putendl(ft_itoa(keycode));
	draw(fdf);
	return (0);
}
