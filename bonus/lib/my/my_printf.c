/*
** my_printf.c for  in /home/belfio_u/rendu/PSU_2014_my_printf
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Wed Nov 12 16:27:21 2014 ugo belfiore
** Last update Mon Nov 24 08:27:50 2014 ugo belfiore
*/

#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "../../include/my.h"

int	my_printf2(va_list ap, const char *format, int i, int cmp)
{
  cmp += (format[i] == '%') ? my_putchar_return('%') : 0;
  cmp += (format[i] == 'c') ? my_putchar_return(va_arg(ap, int)) : 0;
  cmp += (format[i] == 's') ? my_putstr(va_arg(ap, char *)) : 0;
  cmp += (format[i] == 'd' || format[i] == 'i') ? 
    my_putnbr_base_return(va_arg(ap, int), "0123456789"): 0;
  if (format[i] == 'l' && format[i + 1] == 'd')
    {
      cmp +=  my_put_nbr_long(va_arg(ap, long));
      cmp++;
      i++;
    }
  cmp += (format[i] == 'b') ? my_putnbr_base_return(va_arg(ap, int), "01") : 0;
  cmp += (format[i] == 'x' || format[i] == 'X') ? 
    my_putnbr_base_return(va_arg(ap, int), "0123456789ABCDEF"): 0;
  cmp += (format[i] == 'u') ? my_put_nbr_uns(va_arg(ap, unsigned int)) : 0;
  cmp += (format[i] == 'o') ?
    my_putnbr_base_return(va_arg(ap, int), "01234567") : 0;
  cmp += (format[i] == 'S') ? my_put_S(va_arg(ap, char *)) : 0;
  if (format[i] == 'p')
    {
      cmp += my_putstr("0x");
      cmp += my_put_nbr_hexa_P(va_arg(ap, long), "0123456789abcdef");
    }
  return (cmp);
}

int	my_printf3(const char *format, int i, int cmp, int c)
{
  if (format[i] == 'n')
    cmp += my_putnbr_base_return((cmp + i - (c * 2)) + 2,
                                 "0123456789");
  return (cmp);
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		c;
  int		cmp;
  int		i;

  c = 0;
  i = 0;
  cmp = 0;
  va_start(ap, format);
  while (format[i] != '\0')
    {      
      if (format[i] == '%')
      	{
      	  c++;
      	  i++;
	  cmp = my_printf2(ap, format, i, cmp);
	  i += (format[i] == 'l' && format[i + 1] == 'd') ? 1 : 0;
      	  cmp = my_printf3(format, i, cmp, c);
      	}
      else
      	my_putchar_return(format[i]);
      i++;
    }
  va_end(ap);
  return (cmp);
}
