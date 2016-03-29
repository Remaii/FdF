/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Remaii <Remaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 18:53:58 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/29 15:24:26 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

/*
** Static
*/

# define WIDTH 1200
# define HEIGT 800
# define USAGE "./fdf path_to_map.fdf or ./fdf path X_window_size Y_window_size"

/*
** Color
*/

# define B_FNC 0x8b
# define B_CLR 0x87ceeb
# define B_TUR 0x40e0d0
# define JAUNE 0xffffe0
# define V_CLR 0xff7f
# define V_FNC 0x6400
# define M_CLR 0xf4a460
# define M_FNC 0xa52a2a
# define BLANC 0x0FFFFFF
# define AUTRE 0xff69b4

/*
** Structure des points 3D
*/

typedef struct		s_pts
{
	int				x;
	int				y;
	int				z;
}					t_pts;

/*
** Structure des variable utile a FdF
** mlx = pointer pour initialiser mlx
** win = pointer sur la fenetre mlx
** width = Stockage de la largeur de la fenetre
** heigt = Stockage de la hauteur de la fenetre
** *img = Pointer sur l'image
** *idata = Stockage de get_data_addr
** bpp = Bits Per Pixel
** size = get_data_addr
** end = get_data_addr
** draw = 1 si une image a deja ete dessiner
** **map = Tableau de tableau contenant la map convertie
** x = x max
** xoff = position de l'image dans la fenetre
** y = y max
** yoff = position de l'image dans la fenetre
** zoom = de l'image dans la fenetre
** relief = de l'image dans la fenetre
** max = valeur du relief max
** min = valeur du relief min
** diff = difference entre min et max
*/

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	int				width;
	int				heigt;
	int				*img;
	char			*idata;
	int				bpp;
	int				size;
	int				end;
	int				draw;
	int				**map;
	int				x;
	int				xoff;
	int				y;
	int				yoff;
	double			zoom;
	double			relief;
	int				max;
	int				min;
	double			diff;
}					t_mlx;

/*
** ERRNO
*/

void				perror(const char *s);

/*
** utilis.c
*/

void				error(int nb);
void				status(t_mlx *fdf);
void				new_img(t_mlx *f);
int					ft_key(int keycode, t_mlx *fdf);

/*
** color.c
*/

int					wcolor(t_mlx *fdf, int z);
void				set_color(t_mlx *fdf, int z);

/*
** parse.c
*/

void				parsemap(t_mlx *fdf, int fd);

/*
** init.c
*/

void				init(t_mlx *fdf, int ac, char **av);

/*
** iso.c
*/

void				img_put(t_mlx *fdf, int x, int y, int color);
void				vline(t_mlx *fdf, t_pts *pt1, t_pts *pt2, int color);
void				hline(t_mlx *fdf, t_pts *pt1, t_pts *pt2, int color);

/*
** draw.c
*/

int					draw(t_mlx *fdf);

#endif
