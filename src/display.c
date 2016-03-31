/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 10:45:15 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/31 12:15:48 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			set_display(t_mlx *f)
{
	if (f->help == 1)
		f->help = 0;
	else
		f->help = 1;
}

void			display(t_mlx *f)
{
	if (f->help == 1)
	{
		mlx_string_put(f->mlx, f->win, 5, 1, BLANC, B_ESC);
		mlx_string_put(f->mlx, f->win, 5, 15, BLANC, B_Q);
		mlx_string_put(f->mlx, f->win, 5, 31, BLANC, B_A);
		mlx_string_put(f->mlx, f->win, 5, 46, BLANC, B_W);
		mlx_string_put(f->mlx, f->win, 5, 62, BLANC, B_S);
		mlx_string_put(f->mlx, f->win, 5, 78, BLANC, B_R);
		mlx_string_put(f->mlx, f->win, 5, f->heigt - 20, BLANC, UDLR);
		mlx_string_put(f->mlx, f->win, 5, f->heigt - 40, BLANC, B_HF);
	}
	else
		mlx_string_put(f->mlx, f->win, 5, f->heigt - 20, BLANC, B_HO);
}
