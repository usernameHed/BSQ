/*
** my_power_it.c for  in /home/belfio_u/PISCINE/rendu/Piscine_C_J05
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct  3 16:08:27 2014 ugo belfiore
** Last update Thu Nov  6 19:41:04 2014 ugo belfiore
*/

int	my_power_rec(int cute, int power)
{
  int	ness;

  ness = 1;
  if (power < 0)
    return (0);
  if (power > 0)
    {
      ness = my_power_rec(cute, power - 1);
      ness *= cute;
    }
  return (ness);
}
