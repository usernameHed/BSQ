/*
** my_put_nbr.c for  in /home/belfio_u/rendu/PSU_2014_my_printf/lib
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Wed Nov 12 16:06:03 2014 ugo belfiore
** Last update Mon Nov 24 08:28:13 2014 ugo belfiore
*/

#include "../../include/my.h"

int	my_putnbr_base_return(long nb, char *base)
{
  int	cmp;
  long	c;
  int	len;

  cmp = 0;
  c = 1;
  len = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
      cmp++;
    }
  while (nb / c >= len)
    c *= len;
  while (c > 0)
    {
      my_putchar(base[nb / c % len]);
      cmp++;
      c /= len;
    }
  return (cmp);
}

int	my_put_nbr_uns(unsigned int nb)
{
  int	cmp;
  int	c;
  char	*base;

  base = "0123456789";
  cmp = 0;
  c = 1;
  while (nb / c >= 10)
    c *= 10;
  while (c > 0)
    {
      my_putchar(base[nb / c % 10]);
      cmp++;
      c /= 10;
    }
  return (cmp);
}

int	my_put_nbr_long(long nb)
{
  int	cmp;
  long	c;
  char	*base;

  cmp = 0;
  c = 1;
  base = "0123456789";
  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
      cmp++;
    }
  while (nb / c >= 10)
    c *= 10;
  while (c > 0)
    {
      my_putchar(base[nb / c % 10]);
      cmp++;
      c /= 10;
    }
  return (cmp);
}
