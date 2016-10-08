/*
** my_putstr.c for  in /home/belfio_u/rendu/PSU_2014_my_printf/lib
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Wed Nov 12 16:26:13 2014 ugo belfiore
** Last update Mon Nov 24 08:29:04 2014 ugo belfiore
*/

#include "../../include/my.h"

int	my_putstr(char *str)
{
  int	h;
  int	cmp;

  h = 0;
  cmp = 0;
  while (str[h] != '\0')
    {
      my_putchar(str[h]);
      h++;
      cmp++;
    }
  return (cmp);
}
