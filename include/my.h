/*
** my.h for  in /home/belfio_u/PISCINE/rendu/Piscine_C_J09/include
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 10 09:04:55 2014 ugo belfiore
** Last update Sun Dec 14 20:53:21 2014 ugo belfiore
*/

#ifndef	MY_H_
#define	MY_H_

void	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
char	*my_strcat(char *dest, char *src);
void	my_putnbr_base(int nb, char *base);
int	my_getnbr_base(char *str, char *base);
char	*my_strdup(char *tab1);
char	*my_int_char(int nbr);
char	**my_str_to_wordtab(char *str);
void	my_show_wordtab(char **tab);
int	my_rand(unsigned int m);
int     my_putchar_return(char c);
int     my_putnbr_base_return(long nb, char *base);
int     my_put_nbr_long(long nb);
int     my_put_nbr_uns(unsigned int nb);
int     my_put_nbr_hexa_P(unsigned long nb, char *base);
int     my_put_S(char *str);
void    aff_0(int nb);
int     my_put_S(char *str);
int	my_printf(const char *format, ...);
char	*convert_base(char *nbr, char *base_from, char *base_to);

#endif /* !MY_H_ */
