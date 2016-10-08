/*
** my_strdup.c for  in /home/belfio_u/PISCINE/rendu/Piscine_C_J07
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Oct  7 21:31:05 2014 ugo belfiore
** Last update Thu Nov  6 20:13:29 2014 ugo belfiore
*/

#include <stdlib.h>

char	*my_strdup(char *tab1)
{
  int	len;
  char	*tab2;
  int	i;

  i = 0;
  len = my_strlen(tab1);
  tab2 = malloc(len);
  while (tab1[i])
    {
      tab2[i] = tab1[i];
      i++;
    }
  return (tab2);
}
