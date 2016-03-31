/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:26:33 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/31 15:15:53 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int				zcolor2(t_mlx *fdf, int z)
{
	set_color(fdf, z);
	if (z <= fdf->min)
		return (N_OIR);
	else if (z <= ((fdf->diff / 10) * (-0.05)))
		return (B_FNC);
	else if (z <= ((fdf->diff / 10) * 0))
		return (B_CLR);
	else if (z <= ((fdf->diff / 10) * 1))
		return (V_CLR);
	else if (z <= ((fdf->diff / 10) * 2))
		return (V_FNC);
	else if (z <= ((fdf->diff / 10) * 3))
		return (M_CLR);
	else if (z <= ((fdf->diff / 10) * 4))
		return (M_FNC);
	else if (z <= ((fdf->diff / 10) * 8))
		return (BLANC);
	else if (z <= fdf->max)
		return (JAUNE);
	else
		return (AUTRE);
}

int				zcolor1(t_mlx *fdf, int z)
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
