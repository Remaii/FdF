/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 18:53:58 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/17 13:07:11 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "color.h"
# include "mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <math.h>

/*
** Static
*/

# define WIDTH 1200
# define HEIGT 800
# define USAGE "./fdf path_to_map.fdf or ./fdf path X_window_size Y_window_size"

/*
** Commandes
*/

# define B_ESC "Esc to Exit"
# define B_Q "Q to put into relief up"
# define B_A "A to put into relief down"
# define B_W "W to Zoom In"
# define B_S "S to Zoom Out"
# define UDLR "Arrow to Move"
# define B_R "R to Reset position"
# define B_HO "H to show Help"
# define B_HF "H to hide Help"
# define C_NX "C to Change Color:"

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
** help = affiche la legende
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
	int				col;
	int				help;
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
void				new_img(t_mlx *fdf);
int					ft_key(int keycode, t_mlx *fdf);

/*
** color.c
*/

int					wcolor(t_mlx *fdf, int z);
void				set_color(t_mlx *fdf, int z);
void 				set_theme(t_mlx *fdf);

/*
** color2.c
*/

int					zcolor1(t_mlx *fdf, int z);
int					zcolor2(t_mlx *fdf, int z);
int					zcolor3(t_mlx *fdf, int z);
int					zcolor4(t_mlx *fdf, int z);
int					zcolor5(t_mlx *fdf, int z);

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

/*
** display.c
*/

void				display(t_mlx *fdf);
void				set_display(t_mlx *fdf);

#endif
