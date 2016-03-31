/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 04:27:03 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/30 21:11:45 by rthidet          ###   ########.fr       */
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
//	printf("min= %d max= %d\n", fdf->min, fdf->max);
}

int				zcolor(t_mlx *fdf, int z)
{
	set_color(fdf, z);
	if (z <= (fdf->min))
		return (N_OIR);
	else if (z <= (fdf->min + (fdf->diff / 10) - 4))
		return (B_FNC);
	else if (z <= (fdf->min + ((fdf->diff / 10) * 2)))
		return (B_CLR);
	else if (z <= (fdf->min + ((fdf->diff / 10) * 3)))
		return (B_CLR);
	else if (z <= (fdf->min + ((fdf->diff / 10) * 4)))
		return (JAUNE);
	else if (z <= (fdf->min + ((fdf->diff / 10) * 5)))
		return (V_CLR);
	else if (z <= (fdf->min + ((fdf->diff / 10) * 6)))
		return (V_FNC);
	else if (z <= (fdf->min + ((fdf->diff / 10) * 7)))
		return (M_CLR);
	else if (z <= (fdf->min + ((fdf->diff / 10) * 8)))
		return (M_FNC);
	else if (z <= (fdf->min + ((fdf->diff / 10) * 9)))
		return (BLANC);
	else
		return (AUTRE);
}

int				wcolor(t_mlx *fdf, int z)
{
	set_color(fdf, z);
	if (z <= fdf->min)
		return (B_FNC);
	else if (z <= ((fdf->diff / 10) * (-0.05)))
		return (B_CLR);
	else if (z <= ((fdf->diff / 10) * 0))
		return (B_TUR);
	else if (z <= ((fdf->diff / 10) * 1))
		return (JAUNE);
	else if (z <= ((fdf->diff / 10) * 2))
		return (V_CLR);
	else if (z <= ((fdf->diff / 10) * 3))
		return (V_FNC);
	else if (z <= ((fdf->diff / 10) * 4))
		return (M_CLR);
	else if (z <= ((fdf->diff / 10) * 8))
		return (M_FNC);
	else if (z <= fdf->max)
		return (BLANC);
	else
		return (AUTRE);
}
