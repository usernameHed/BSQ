/*
** aff_pix_img.c for  in /home/belfio_u/rendu/CPE_2014_bsq
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Dec 15 18:24:02 2014 ugo belfiore
** Last update Tue Dec 23 22:37:42 2014 ugo belfiore
*/

#include "./lib/minilibx/mlx.h"
#include "./include/mini.h"
#include "./include/my.h"

/*
** affiche un pixel à l'écran aux position x et y.
** (gère l'endian pour afficher la couleur en RGB ou BGR).
*/

void	aff_pix_img(t_data *d, int x, int y)
{
  int	i;

  if (x < 0 || x >= d->x_max)
    return;
  if (y < 0 || y >= d->y_max)
    return;
  if (d->endian == 0)
    {
      i = (d->sizeline * y) + (x * (d->bpp / 8));
      d->bigData[i] = mlx_get_color_value(d->mlx_ptr, d->colo);
      d->bigData[i + 1] = mlx_get_color_value(d->mlx_ptr, d->colo >> 8);
      d->bigData[i + 2] = mlx_get_color_value(d->mlx_ptr, d->colo >> 16);
    }
  else
    {
      i = (d->sizeline * y) + (x * (d->bpp / 8));
      d->bigData[i] = mlx_get_color_value(d->mlx_ptr, d->colo >> 16);
      d->bigData[i + 1] = mlx_get_color_value(d->mlx_ptr, d->colo >> 8);
      d->bigData[i + 2] = mlx_get_color_value(d->mlx_ptr, d->colo);
    }
}

/*
** affiche un rectangle de (x1, y1) à (x2, y2);
*/

void	aff_rec(t_data *d, int x1, int y1, int x2, int y2)
{
  int	i;
  int	j;

  i = x1;
  j = y1;
  while (i++ <= x2)
    {
      while (j++ <= y2)
	aff_pix_img(d, i, j);
      j = y1;
    }
}
