/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 04:27:03 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/22 13:40:56 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int			wcolor(t_mlx *fdf, int z)
{
	if (z <= ((fdf->diff / 10) * (-0.08)))
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
	else if (z <= ((fdf->diff / 10) * 10))
		return (BLANC);
	else
		return (AUTRE);
}

static int			count_diff(int nb1, int nb2)
{
	int		i;

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

void		set_color(t_mlx *fdf, int z)
{
	fdf->min = ft_min(z, fdf->min);
	fdf->max = ft_max(z, fdf->max);
	fdf->diff = count_diff(fdf->min, fdf->max);
}
