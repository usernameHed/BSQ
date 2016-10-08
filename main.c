/*
** main.c for  in /home/belfio_u/rendu/CPE_2014_bsq
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Dec 15 18:39:45 2014 ugo belfiore
** Last update Thu Jan 15 16:34:04 2015 ugo belfiore
*/

#include "./include/my.h"
#include "./include/mini.h"

void		launch(t_file *f)
{
  t_data	d;

  d.tab = f->tab;
  d.x_file = f->x_file;
  d.y_file = f->y_file;
  d.hed = 1;
  d.c.x = -1;
  d.c.y = -1;
  d.c.posX = 0;
  d.c.posY = 0;
  d.c.hunt = 1;
  algo_bsq(&d);
}

int		main(int ac, char **av)
{
  int		fd;
  t_file	f;
  int		rett;

  ac = (ac == 2) ? ac : ac;
  fd = open(av[1], O_RDONLY);
  if (fd == -1)
    {
      my_printf("ERROR: can't open file\n");
      close(fd);
      return (0);
    }
  rett = read(fd, f.buff, 8192000);
  if (rett == 0 || rett > 8191999)
    exit(0);
  my_str_to_wordtab_bsq(&f);
  launch(&f);
  close(fd);
  return (0);
}
