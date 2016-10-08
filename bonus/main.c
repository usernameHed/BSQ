/*
** main.c for  in /home/belfio_u/rendu/CPE_2014_bsq
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Dec 15 18:39:45 2014 ugo belfiore
** Last update Thu Jan 15 15:08:37 2015 ugo belfiore
*/

#include "./include/my.h"
#include "./lib/minilibx/mlx.h"
#include "./include/mini.h"

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
  rett = read(fd, f.buff, 2048000);
  if (rett == 0 || rett > 2047999)
    exit(0);
  my_str_to_wordtab_bsq(&f);
  aff_win("BSQ -   FU**ING BSQ   - BSQ", 1000, 700, &f);
  close(fd);
  return (0);
}
