/*
** my_putnbr_base_printf2.c for  in /home/belfio_u/rendu/PSU_2014_my_printf/lib
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Wed Nov 12 23:34:34 2014 ugo belfiore
** Last update Mon Nov 24 08:28:27 2014 ugo belfiore
*/

#include "../../include/my.h"

int	my_put_nbr_hexa_P(unsigned long nb, char *base)
{
  long	bin;
  long	result;
  int	cmp;
  unsigned int	len;

  cmp = 0;
  bin = 1;
  len = my_strlen(base);
  while (nb / bin >= len)
    bin *= len;
  while (bin > 0)
    {
      result = (nb / bin) % len;
      my_putchar(base[result]);
      cmp++;
      bin /= len;
    }
  return (cmp);
}

int	my_put_oct_S(int nb, char *base)
{
  int	bin;
  int	len;

  len = my_strlen(base);
  my_putchar('\\');
  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
    }
  bin = 1;
  if (nb <= 31)
    aff_0(nb);
  while (nb / bin >= len)
    bin *= len;
  while (bin > 0)
    {
      my_putchar(base[(nb / bin) % len]);
      bin /= len;
    }
  return (1);
}

void	aff_0(int nb)
{
  my_putchar('0');
  if (nb < 7)
    my_putchar('0');
}

int	my_put_S(char *str)
{
  int	h;
  int	cmp;
  int	cmp2;

  h = 0;
  cmp = 0;
  cmp2 = 0;
  while (str[h] != '\0')
    {
      if (str[h] < 32 || str[h] >= 127)
        {
          cmp2 += my_put_oct_S(str[h], "01234567");
          cmp++;
          h++;
        }
      my_putchar(str[h]);
      cmp++;
      h++;
    }
  return (cmp + cmp2);
}
