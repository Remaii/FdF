/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:22:56 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/22 21:53:20 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

void	status(t_mlx *fdf)
{
	printf("x= %d y= %d width= %d heigt= %d bpp= %d size= %d end= %d\n", fdf->x, fdf->y, fdf->width, fdf->heigt, fdf->bpp, fdf->size, fdf->end);
	printf("xoff= %d yoff= %d max= %d min= %d idata= %s zoom= %f relief= %f\n", fdf->xoff, fdf->yoff, fdf->max, fdf->min, fdf->idata, fdf->zoom, fdf->relief);
	test(fdf);
}

void	ft_stop(t_mlx *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

int		ft_key(int keycode, t_mlx *fdf)
{
			mlx_clear_window(fdf->mlx, fdf->win);
			fdf->test = 0;
	if (keycode == 53 || keycode == 17)/* ESC */
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
		fdf->relief += 1.05;
	else if (keycode == 0)/* A */
		fdf->relief -= 1.05;
	else if (keycode == 46)/* M */
		status(fdf);
	else if (keycode == 15)/* R */
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		fdf->test = 0;
		/*fdf->xoff = (fdf->width / 2);
		fdf->yoff = (fdf->heigt / 2);
*/	}
	else
		ft_putendl(ft_itoa(keycode));
	test(fdf);
	return (0);
}
