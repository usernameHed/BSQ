/*
** my_putchar.c for  in /home/belfio_u/rendu/PSU_2014_my_printf/lib
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Wed Nov 12 16:05:22 2014 ugo belfiore
** Last update Wed Nov 12 23:15:44 2014 ugo belfiore
*/

int	my_putchar_return(char c)
{
  write(1, &c, 1);
  return (1);
}
