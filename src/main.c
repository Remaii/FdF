/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 13:32:53 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/23 09:44:40 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	error(int nb)
{
	if (nb == 0)
		ft_putendl("Error mlx_init");
	else if (nb == 1)
		perror("Error:");
	else if (nb == 2)
		ft_putendl(USAGE);
	else
		perror("Perror:");
	exit(0);
}

int		main(int ac, char **av)
{
	int fd;
	t_mlx fdf;

	init(&fdf, ac, av);
	fd = open(av[1], O_RDONLY);
	parsemap(&fdf, fd);
	mlx_expose_hook(fdf.win, test, &fdf);
	mlx_key_hook(fdf.win, ft_key, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
