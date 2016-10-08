/*
** convert_base.c for  in /home/belfio_u/rendu/MUL_2014_wolf3d/lib/my
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sun Dec 14 20:41:22 2014 ugo belfiore
** Last update Sun Dec 14 20:46:30 2014 ugo belfiore
*/

#include <stdlib.h>
#include "../../include/my.h"

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  int	i;
  int	nb;
  char	*res;

  i = 0;
  res = malloc(sizeof(char) * 300);
  nb = my_getnbr_base(nbr, base_from);
  while (nb > 0)
    {
      res[i] = base_to[nb % my_strlen(base_to)];
      nb = nb / my_strlen(base_to);
      i = i + 1;
    }
  res[i] = '\0';
  res = my_revstr(res);
  return (res);
}
