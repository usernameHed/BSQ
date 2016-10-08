/*
** aff_bsq.c for  in /home/belfio_u/rendu/CPE_2014_bsq
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Dec 23 22:58:57 2014 ugo belfiore
** Last update Thu Jan 15 16:37:59 2015 ugo belfiore
*/

#include "./include/mini.h"
#include "./include/my.h"

static void	algo_bsq_x(t_data *d)
{
  d->c.size = algo_find_size(d, d->c.x, d->c.y);
  if (d->c.size == d->c.size_max)
    {
      if (d->c.y < d->c.posY)
  	{
  	  d->c.posX = d->c.x;
  	  d->c.posY = d->c.y;
  	}
      else if (d->c.y == d->c.posY)
  	{
  	  if (d->c.x <= d->c.posX)
  	    {
  	      d->c.posX = d->c.x;
  	      d->c.posY = d->c.y;
  	    }
  	}
    }
  else if (d->c.size > d->c.size_max)
    {
      d->c.size_max = d->c.size;
      d->c.posX = d->c.x;
      d->c.posY = d->c.y;
    }
  if (d->x_file - d->c.x < d->c.size_max)
    d->c.x = d->x_file;
}

void		algo_bsq(t_data *d)
{
  d->c.size_max = 0;
  d->c.y = -1;
  d->c.x = -1;
  while (++d->c.y < d->y_file)
    {
      while (++d->c.x < d->x_file)
	algo_bsq_x(d);
      d->c.x = -1;
      if (d->y_file - d->c.y < d->c.size_max)
      	d->c.y = d->y_file;
    }
  algo_do_block(d, d->c.posX, d->c.posY, d->c.size_max);
  aff_bsq(d);
}

void	aff_bsq(t_data *d)
{
  int	x;
  int	y;

  x = -1;
  y = -1;
  while (++y < d->y_file)
    {
      while (++x < d->x_file)
	if (d->tab[y][x] == 0)
	  my_printf(".");
	else if (d->tab[y][x] == -1)
	  my_printf("o");
	else
	  my_printf("x");
      x = -1;
      my_printf("\n");
    }
}
