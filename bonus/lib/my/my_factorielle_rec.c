/*
** my_factorielle_rec.c for  in /home/belfio_u/PISCINE/rendu/Piscine_C_J05
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct  3 10:16:30 2014 ugo belfiore
** Last update Thu Nov  6 19:39:36 2014 ugo belfiore
*/

int	my_factorielle_rec(int cute)
{
  int	ness;

  ness = cute;
  if (ness < 1 || ness >= 13)
    return (0);
  if (ness == 1)
    return (1);
  else
    return (cute * my_factorielle_rec(ness - 1));
}
