/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Remaii <Remaii@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 18:53:58 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/29 12:25:02 by Remaii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
/** Static **/
# define WIDTH 1200
# define HEIGT 800
# define USAGE "./fdf path_to_map.fdf or ./fdf path X_window_size Y_window_size"

/** Color **/
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

/** Structure des points 3D**/
typedef struct		s_pts
{
	int				x;
	int				y;
	int				z;
}					t_pts;

/** Structure des variable utile a FdF **/
typedef struct		s_mlx
{
	void			*mlx;/*pointer pour initialiser mlx*/
	void			*win;/*pointer sur la fenetre mlx*/
	int				width;/*Stockage de la largeur de la fenetre*/
	int				heigt;/*Stockage de la hauteur de la fenetre*/
	int				*img;/*Pointer sur l'image*/
	char			*idata;/*Stockage de get_data_addr*/
	int				bpp;/*Bits Per Pixel*/
	int				size;/*get_data_addr*/
	int				end;/*get_data_addr*/
	int				draw;
	int				**map;/*Tableau de tableau contenant la map convertie*/
	int				x;/*x max*/
	int				xoff;/*position de l'image dans la fenetre*/
	int				y;/*y max*/
	int				yoff;/*position de l'image dans la fenetre*/
	double			zoom;/*de l'image dans la fenetre*/
	double			relief;/*de l'image dans la fenetre*/
	int			rot;/* rotation de l'image*/
	int				max;/*valeur du relief max*/
	int				min;/*valeur du relief min*/
	double			diff;/*difference entre min et max*/
}					t_mlx;

/** ERRNO **/
void				perror(const char *s);/*return type d'erreur*/

/** utilis.c **/
void				error(int nb);/*donne le choix de l'erreur*/
void				status(t_mlx *fdf);
void				new_img(t_mlx *f);/*supp l'image actuel & cree une nouvel */
int					ft_key(int keycode, t_mlx *fdf);/*permet l'interaction entre
													la fenetre & le clavier*/

/** color.c**/
int					wcolor(t_mlx *fdf, int z);
void				set_color(t_mlx *fdf, int z);

/** parse.c **/
void				parsemap(t_mlx *fdf, int fd);/*split l'entre & save les\
									coordonnees, x, y, z dans map[x][y] = z*/

/** init.c **/
void				init(t_mlx *fdf, int ac, char **av);/*initialise la\
													Structure t_mlx fdf*/

/** iso.c **/
void				img_put(t_mlx *fdf, int x, int y, int color);
void				vline(t_mlx *fdf, t_pts *pt1, t_pts *pt2, int color);
void				hline(t_mlx *fdf, t_pts *pt1, t_pts *pt2, int color);

/** draw.c **/
int					draw(t_mlx *fdf);

#endif
