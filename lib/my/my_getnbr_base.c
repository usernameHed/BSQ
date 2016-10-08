/*
** my_putnbr_base.c for  in /home/belfio_u/PISCINE/rendu/Piscine_C_J06/ex_15
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 10 17:40:01 2014 ugo belfiore
** Last update Thu Nov  6 20:05:31 2014 ugo belfiore
*/

int	my_getnbr_baseBIS(char c, char *base)
{
  int	pos;

  pos = 0;
  while (*(base + pos) && *(base + pos) != c)
    pos++;
  if (*(base + pos))
    return (pos);
  else
    return (-1);
}

int	my_getnbr_base(char *str, char *base)
{
  int	res;
  int	len;

  if (*str == '-')
    return (-my_getnbr_base(str + 1, base));
  if (*str == '+')
    return (my_getnbr_base(str + 1, base));
  len = my_strlen(base);
  res = 0;
  while (*str)
    {
      res *= len;
      res += my_getnbr_baseBIS(*str, base);
      str++;
    }
  return (res);
}
