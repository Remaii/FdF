/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Remaii <Remaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 13:32:53 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/29 15:51:02 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		error(int nb)
{
	if (nb == 0)
		ft_putendl("Error mlx_init");
	else if (nb == 1)
		perror("Error:");
	else if (nb == 2)
		ft_putendl(USAGE);
	else if (nb == 3)
		ft_putendl("Invalid map");
	else
		perror("Perror:");
	exit(0);
}

int			main(int ac, char **av)
{
	int		fd;
	t_mlx	fdf;

	init(&fdf, ac, av);
	fd = open(av[1], O_RDONLY);
	parsemap(&fdf, fd);
	mlx_expose_hook(fdf.win, draw, &fdf);
	mlx_key_hook(fdf.win, ft_key, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
