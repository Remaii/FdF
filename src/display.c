/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 10:45:15 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/17 13:09:41 by rthidet          ###   ########.fr       */
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

void			dis_color(t_mlx *f)
{
	mlx_string_put(f->mlx, f->win, 3, f->heigt - 60, BLANC, C_NX);
	if (f->col == 1)
		mlx_string_put(f->mlx, f->win, 190, f->heigt - 60, BLANC, "Theme 1");
	else if (f->col == 2)
		mlx_string_put(f->mlx, f->win, 190, f->heigt - 60, BLANC, "Theme 2");
	else if (f->col == 3)
		mlx_string_put(f->mlx, f->win, 190, f->heigt - 60, BLANC, "Theme 3");
	else if (f->col == 4)
		mlx_string_put(f->mlx, f->win, 190, f->heigt - 60, BLANC, "Theme 4");
	else if (f->col == 5)
		mlx_string_put(f->mlx, f->win, 190, f->heigt - 60, BLANC, "Theme 5");
	else
		mlx_string_put(f->mlx, f->win, 190, f->heigt - 60, BLANC, "Inconue");
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
		mlx_string_put(f->mlx, f->win, 5, f->heigt - 40, BLANC, UDLR);
		mlx_string_put(f->mlx, f->win, 5, f->heigt - 20, BLANC, B_HF);
		dis_color(f);
	}
	else
		mlx_string_put(f->mlx, f->win, 5, f->heigt - 20, BLANC, B_HO);
}
