/*
** aff_bsq.c for  in /home/belfio_u/rendu/CPE_2014_bsq
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Dec 23 22:58:57 2014 ugo belfiore
** Last update Mon Feb  1 09:33:48 2016 Ugo Belfiore
*/

#include "./lib/minilibx/mlx.h"
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
  algo_do_block(d, d->c.posX, d->c.posY, d->c.size_max);
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
  d->c.y = 0;
  d->c.x = 0;
  while (++d->c.y < d->y_file)
    {
      while (++d->c.x < d->x_file)
	algo_bsq_x(d);
      d->c.x = -1;
      if (d->y_file - d->c.y < d->c.size_max)
	{
      	d->c.y = d->y_file;
  algo_do_block(d, d->c.posX, d->c.posY, d->c.size_max);
	}
    }
  algo_do_block(d, d->c.posX, d->c.posY, d->c.size_max);
  aff_bsq(d);
}

void	aff_bsq(t_data *d)
{
  t_bsq	b;

  b.i = -1;
  b.j = -1;
  b.cube = (d->x_file > d->y_file) ?
    ((d->y_max / 8) * 8) / d->x_file
    : ((d->y_max / 8) * 8) / d->y_file;
  b.top = (d->y_max / 20);
  while (++b.j < d->y_file)
    {
      while (++b.i < d->x_file)
	{
	  d->colo = (d->tab[b.j][b.i] == 0) ? COLOR_BLACK : d->colo;
	  d->colo = (d->tab[b.j][b.i] == -1) ? COLOR_RED : d->colo;
	  d->colo = (d->tab[b.j][b.i] == 1) ? COLOR_G1 : d->colo;
	  aff_rec(d,
		  b.top + (b.i * b.cube),
		  b.top + (b.j * b.cube),
		  b.top + ((b.i + 1) * b.cube),
		  b.top + ((b.j + 1) * b.cube));
	}
      b.i = -1;
    }
  mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
}
