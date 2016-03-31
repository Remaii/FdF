/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 18:51:44 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/31 13:24:38 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		initmlx(t_mlx *fdf)
{
	if ((fdf->mlx = mlx_init()) == NULL)
		error(0);
	fdf->win = mlx_new_window(fdf->mlx, fdf->width, fdf->heigt, "FdF");
	fdf->img = mlx_new_image(fdf->mlx, fdf->width, fdf->heigt);
	fdf->idata = mlx_get_data_addr(fdf->img, &(fdf->bpp),\
									&(fdf->size), &(fdf->end));
	fdf->xoff = 0;
	fdf->yoff = 0;
	fdf->draw = 0;
	fdf->help = 1;
}

void			init(t_mlx *fdf, int ac, char **av)
{
	if (ac == 2)
	{
		fdf->width = WIDTH;
		fdf->heigt = HEIGT;
		initmlx(fdf);
	}
	else if (ac == 4)
	{
		fdf->heigt = ft_atoi(av[3]);
		fdf->width = ft_atoi(av[2]);
		initmlx(fdf);
	}
	else
		error(2);
}
