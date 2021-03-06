/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 04:27:03 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/17 13:11:07 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int		count_diff(int nb1, int nb2)
{
	int			i;

	i = 0;
	if (nb1 < nb2)
		while (nb1 != nb2)
		{
			nb1++;
			i++;
		}
	else
		while (nb2 != nb1)
		{
			nb2++;
			i++;
		}
	return (i);
}

void			set_color(t_mlx *fdf, int z)
{
	fdf->min = ft_min(z, fdf->min);
	fdf->max = ft_max(z, fdf->max);
	fdf->diff = count_diff(fdf->min, fdf->max);
}

int				wcolor(t_mlx *f, int z)
{
	if (f->col == 1)
		return(zcolor1(f, z) + z);
	if (f->col == 2)
		return (zcolor2(f, z) + z);
	if (f->col == 3)
		return (zcolor3(f, z) + z);
	if (f->col == 4)
		return (zcolor4(f, z) + z);
	if (f->col == 5)
		return (zcolor5(f, z) + z);
	else
	{
		f->col = 1;
		return (wcolor(f, z));
	}
}

void 			set_theme(t_mlx *f)
{
	if (f->col < 6)
		f->col++;
	else
		f->col = 1;
}
