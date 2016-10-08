/*
** aff_bsq_carre.c for  in /home/belfio_u/rendu/CPE_2014_bsq
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Wed Dec 24 15:52:44 2014 ugo belfiore
** Last update Mon Feb  1 09:34:45 2016 Ugo Belfiore
*/

#include "./lib/minilibx/mlx.h"
#include "./include/mini.h"
#include "./include/my.h"

int	algo_find_size(t_data *d, int x, int y)
{
  int	size;
  int	tmp_sizeX;
  int	tmp_sizeY;
  int	i;

  i = 0;
  tmp_sizeX = (d->x_file - x);
  tmp_sizeY = (d->y_file - y);
  size = (tmp_sizeX > tmp_sizeY) ? tmp_sizeY : tmp_sizeX;
  while (i < size)
    if (d->tab[y][x] == -1)
      size = i;
    else
      {
        size -= i;
        size = algo_find_size_forward(d, x, y, size, i);
        y++;
        x++;
        i++;
      }
  return (size);
}

static void	algo_size_bad(t_data *d, t_find *fi, int x, int y)
{
  fi->rank_y = y;
  fi->rank_x = x;
  fi->bad = 1;
  while (fi->rank_x < (x + fi->size) && fi->bad == 1)
    {
      if (d->tab[fi->rank_y][fi->rank_x] == -1)
	fi->bad = 0;
      else
	fi->rank_x++;
    }  
}

int	algo_find_size_forward(t_data *d, int x, int y, int size, int i)
{
  t_find	fi;

  fi.size = size;
  algo_size_bad(d, &fi, x, y);
  fi.tmp_sizeX = fi.rank_x - x;
  fi.rank_x = x;
  fi.bad = 1;
  while (fi.rank_y < (y + size) && fi.bad == 1)
    {
      if (d->tab[fi.rank_y][fi.rank_x] == -1)
  	fi.bad = 0;
      else
  	fi.rank_y++;
    }
  fi.tmp_sizeY = fi.rank_y - y;
  size = (fi.tmp_sizeX < fi.tmp_sizeY) ? fi.tmp_sizeX : fi.tmp_sizeY;
  size += i;
  return (size);
}

void	algo_do_block(t_data *d, int x, int y, int size)
{
  int	tmpx;
  int	tmpy;

  tmpx = x;
  tmpy = y;
  while (y < tmpy + size)
    {
      while (x < tmpx + size)
        {
          if (d->tab[y][x] != -1)
            d->tab[y][x] = d->hed;
          x++;
        }
      x = tmpx;
      y++;
    }
aff_bsq(d);
}
