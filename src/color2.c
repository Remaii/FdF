/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:26:33 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/03 14:30:12 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int				zcolor5(t_mlx *fdf, int z)
{
	set_color(fdf, z);
	if (z <= fdf->min)
		return (BLEU);
	else if (z <= ((fdf->diff / 10) * (-0.05)))
		return (GREEN);
	else if (z <= ((fdf->diff / 10) * 0))
		return (GOLD);
	else if (z <= ((fdf->diff / 10) * 1))
		return (VIOLET);
	else if (z <= ((fdf->diff / 10) * 2))
		return (MAGENTA);
	else if (z <= ((fdf->diff / 10) * 3))
		return (ORANGE);
	else if (z <= ((fdf->diff / 10) * 4))
		return (ROUGE1);
	else if (z <= ((fdf->diff / 10) * 8))
		return (TURQUOISE);
	else if (z <= fdf->max)
		return (TOMATO);
	else
		return (ROSE_FLASH);
}

int				zcolor4(t_mlx *fdf, int z)
{
	set_color(fdf, z);
	if (z <= fdf->min)
		return (PURPLE);
	else if (z <= ((fdf->diff / 10) * (-0.05)))
		return (VERT_FLASH);
	else if (z <= ((fdf->diff / 10) * 0))
		return (BLEU_CLR1);
	else if (z <= ((fdf->diff / 10) * 1))
		return (LIME);
	else if (z <= ((fdf->diff / 10) * 2))
		return (MAGENTA);
	else if (z <= ((fdf->diff / 10) * 3))
		return (ORANGE);
	else if (z <= ((fdf->diff / 10) * 4))
		return (BLE_VIOLET);
	else if (z <= ((fdf->diff / 10) * 8))
		return (FANTOME);
	else if (z <= fdf->max)
		return (SP_GREEN);
	else
		return (ROSE_FLASH);
}

int				zcolor3(t_mlx *fdf, int z)
{
	set_color(fdf, z);
	if (z <= fdf->min)
		return (NOIR);
	else if (z <= ((fdf->diff / 10) * (-0.05)))
		return (GREEN);
	else if (z <= ((fdf->diff / 10) * 0))
		return (VIOLET_FNC);
	else if (z <= ((fdf->diff / 10) * 1))
		return (VIOLET);
	else if (z <= ((fdf->diff / 10) * 2))
		return (FUSHIA);
	else if (z <= ((fdf->diff / 10) * 3))
		return (RED);
	else if (z <= ((fdf->diff / 10) * 4))
		return (ORANGE);
	else if (z <= ((fdf->diff / 10) * 8))
		return (JAUNE);
	else if (z <= fdf->max)
		return (BLANC);
	else
		return (ROSE_FLASH);
}

int				zcolor2(t_mlx *fdf, int z)
{
	set_color(fdf, z);
	if (z <= fdf->min)
		return (NOIR);
	else if (z <= ((fdf->diff / 10) * (-0.05)))
		return (DARKBLUE);
	else if (z <= ((fdf->diff / 10) * 0))
		return (BLEU_CLR1);
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
		return (B_CLR);
	else
		return (ROSE_FLASH);
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
		return (ROSE_FLASH);
}
