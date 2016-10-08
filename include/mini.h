/*
** mini.h for  in /home/belfio_u/rendu/CPE_2014_bsq/include
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Dec 15 18:39:03 2014 ugo belfiore
** Last update Thu Jan 15 16:34:06 2015 ugo belfiore
*/

#ifndef MINI_H_
#define MINI_H_

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

typedef struct	s_data
{
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
  char          buff[8192000];
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

int	cute_word(char *av);
int	cute_char(char *av, int *i);
void	cute_file(t_file *f);
void	my_str_to_wordtab_bsq(t_file *f);
void	launch(t_file *f);
void	aff_bsq_clean(t_data *d);
void	algo_bsq(t_data *d);
void	aff_bsq(t_data *d);
void	algo_do_block(t_data *d, int x, int y, int size);
int	algo_find_size(t_data *d, int x, int y);
int	algo_find_size_forward(t_data *d, int x, int y, int size, int i);

#endif
