/*
** evenement.c for  in /home/belfio_u/rendu/CPE_2014_bsq
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Dec 15 18:24:14 2014 ugo belfiore
** Last update Fri Jan  2 07:58:47 2015 ugo belfiore
*/

#include "./lib/minilibx/mlx.h"
#include "./include/mini.h"
#include "./include/my.h"

/*
** evenememnt clavier.
*/

void	quitt(t_data *d)
{
  mlx_destroy_window(d->mlx_ptr, d->win_ptr);
  exit(1);
}

int		manage_key(int keycode, void *param)
{
  t_data	*d;

  d = (t_data *)param;
  if (keycode == KEY_KILL || keycode == KEY_ESC)
    quitt(d);
  return (0);
}

/*
** evenement expose
** est appelé dès que la fenêtre à besoin d'être recalculé.
*/

int		manage_expose(void *param)
{
  t_data	*d;

  d = (t_data *)param;
  mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
  return (0);
}

/*
** la boucle loop se répète et appelera tout les évenement nécessaire.
*/

void		aff_win(char *name, int x_max, int y_max, t_file *f)
{
  t_data	d;

  d.x_max = x_max;
  d.y_max = y_max;
  d.tab = f->tab;
  d.x_file = f->x_file;
  d.y_file = f->y_file;
  d.hed = 1;
  d.colo = COLOR_BACKWARD;
  d.c.x = -1;
  d.c.y = -1;
  d.c.posX = 0;
  d.c.posY = 0;
  d.c.hunt = 1;
  d.mlx_ptr = mlx_init();
  if (d.mlx_ptr == NULL)
    exit(0);
  d.win_ptr = mlx_new_window(d.mlx_ptr, x_max, y_max, name);
  d.img_ptr = mlx_new_image(d.mlx_ptr, x_max, y_max);
  d.bigData = mlx_get_data_addr(d.img_ptr, &d.bpp, &d.sizeline, &d.endian);
  aff_rec(&d, 0, 0, d.x_max, d.y_max);
  algo_bsq(&d);
  mlx_expose_hook(d.win_ptr, &manage_expose, (void *)(&d));
  mlx_hook(d.win_ptr, 2, 3, &manage_key, (void *)(&d));
  mlx_loop(d.mlx_ptr);
}
