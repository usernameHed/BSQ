/*
** my_int_char.c for my_int_char in /home/belfio_u
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Oct 21 16:01:36 2014 ugo belfiore
** Last update Thu Nov  6 20:39:00 2014 ugo belfiore
*/

#include <stdlib.h>

char	*nega(int neg, char* tab, int c)
{
  if (neg)
    {
      while (c >= 0)
        {
          tab[c + 1] = tab[c];
          c--;
        }
      tab[0] = '-';
    }
  return (tab);
}

int	division(int nbr, int div)
{
  int	c;
  
  c = 0;
  while (nbr/div >= 1)
    {
      div *= 10;
      c++;
    }
  return (c);
}

char	*my_int_char(int nbr)
{
  char	*tab;
  int	count;
  int	div;
  int	c;
  int	neg;

  div = 1;
  neg = 0;
  count = 0;
  if (nbr < 0)
    {
      nbr *= -1;
      neg = 1;
    }
  c = division(nbr, div);
  tab = malloc(20);
  div = 1;
  while (c >= count)
    {
      tab[c - (count + 1)] = nbr / div % 10 + 48;
      div *= 10;
      count++;
    }
  tab = nega(neg, tab, c);
  return (tab);
}
