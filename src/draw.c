/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 11:53:31 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/21 13:23:16 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

void			put_pixel(t_mlx *fdf, int y, int x, int z)
{
	
	mlx_pixel_put(fdf->mlx, fdf->win, x, y, wcolor(fdf, z));
}

void			test(int **map, t_mlx *fdf)
{
	int i;
	int j;

	i = 0;
	while (i <= (fdf->y * 2))
	{
		j = 0;
		while (j <= fdf->x)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, i, j, wcolor(fdf, map[i][j]));
			printf(/*map[%d][%d] =*/"%d ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
		if (!map[i])
			break ;
	}
}
