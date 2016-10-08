/*
** mini.h for  in /home/belfio_u/rendu/CPE_2014_bsq/include
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Dec 15 18:39:03 2014 ugo belfiore
** Last update Thu Jan 15 15:08:40 2015 ugo belfiore
*/

#ifndef MINI_H_
#define MINI_H_

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <time.h>

/*
** define: couleur en hexadécimale.
*/

#define COLOR_BACKWARD 0x9F97A7
#define COLOR_BLACK 0x000000
#define COLOR_WHITE 0xFFFFFF
#define COLOR_RED 0xFF0000
#define COLOR_PURPLE 0xFF00FF
#define COLOR_BLUE 0x0033FF
#define COLOR_G1 0x66FFFF
#define COLOR_G2 0x66FFCC
#define COLOR_G3 0x66FF99
#define COLOR_G4 0x66FF66
#define COLOR_G5 0x66FF33
#define COLOR_G6 0x33FF00
#define COLOR_G7 0x33CC00
#define COLOR_G8 0x339900
#define COLOR_G9 0x336600
#define COLOR_G10 0x333300

/*
** define: clavier.
*/

#define KEY_ENTER 65293
#define KEY_ESC 65307
#define KEY_REFRESH 65471
#define KEY_KILL 107
#define KEY_RIGHT 65363
#define KEY_LEFT 65361
#define KEY_UP 65362
#define KEY_DOWN 65364

typedef struct	s_find
{
  int		bad;
  int		rank_x;
  int		rank_y;
  int		tmp_sizeX;
  int		tmp_sizeY;
  int		size;
}		t_find;

typedef struct	s_carre
{
  int		hunt;
  int		size;
  int		size_max;
  int		y;
  int		x;
  int		i;
  int		posX;
  int		posY;
}		t_carre;

/*
** affichage de la map
*/

typedef struct	s_bsq
{
  int		i;
  int		j;
  int		cube;
  int		top;
  int		stay;
}		t_bsq;

/*
** data: structure principale contenant les pointeurs
**	de fenêtreet d'image, contient le tableau **tab.
*/

typedef struct	s_data
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*bigData;
  int		x_max;
  int		y_max;
  int		colo;
  int		bpp;
  int		sizeline;
  int		endian;
  int		**tab;
  int		x_file;
  int		y_file;
  int		hed;
  t_carre	c;
}               t_data;

/*
** file: variable du parsing du fichier.
** enregistre le fichier dans **tab,
**	enregistre les dimensions du ficher dans x/y_file
*/

typedef struct	s_file
{
  char          buff[2048000];
  int		word;
  int		**tab;
  int		x_file;
  int		y_file;
  int           x_pos;
  int           y_pos;
  int		i;
  int		j;
  int		bufi;
  int		wrong;
}		t_file;

/*
** fonction divers.
*/

void	aff_pix_img(t_data *d, int x, int y);
void	aff_rec(t_data *d, int x1, int y1, int x2, int y2);
int	cute_word(char *av);
int	cute_char(char *av, int *i);
void	cute_file(t_file *f);
void	my_str_to_wordtab_bsq(t_file *f);
void	aff_win(char *name, int x_max, int y_max, t_file *f);
void	aff_bsq_clean(t_data *d);
void	algo_bsq(t_data *d);
void	aff_bsq(t_data *d);
void	algo_do_block(t_data *d, int x, int y, int size);
int	algo_find_size(t_data *d, int x, int y);
int	algo_find_size_forward(t_data *d, int x, int y, int size, int i);

#endif
