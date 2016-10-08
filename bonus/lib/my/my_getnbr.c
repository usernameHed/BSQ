/*
** my_getnbr.c for  in /home/belfio_u/rendu/MUL_2014_wolf3d/lib/my
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Dec  2 17:14:54 2014 ugo belfiore
** Last update Tue Dec  2 17:14:55 2014 ugo belfiore
*/

int     my_getnbr(char *str)
{
  int   nb;
  int   sign;
  int   i;

  nb = 0;
  sign = 0;
  i = 0;
  if (!str)
    return (0);
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    if (str[i++] == '-')
      ++sign;
  while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
    nb = (nb * 10) + (str[i++] - '0');
  return (((sign % 2) == 1) ? ((nb) * (-1)) : (nb));
}
