/*
** my_str_to_wordtab_bsq.c for  in /home/belfio_u/rendu/CPE_2014_bsq
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Dec 15 19:07:12 2014 ugo belfiore
** Last update Wed Dec 24 16:10:28 2014 ugo belfiore
*/

#include "./include/my.h"
#include "./include/mini.h"

static int	cute_y(char *av)
{
  int		i;
  int		cpt;
  char		*nbr;

  i = -1;
  while (av[++i] != '\n')
    if (av[i] == '\0' || (av[i] < '0' || av[i] > '9' || av[0] == '0'))
      {
	my_printf("wrong sizeline.\n");
	exit(0);
      }
  if (i > 9)
    {
      my_printf("oversized sizeline.\n");
      exit(0);
    }
  nbr = malloc(sizeof(char) * i + 1);
  (nbr == NULL) ? exit(0) : 1;
  i = -1;
  while (av[++i] != '\n')
    nbr[i] = av[i];
  nbr[i] = '\0';
  cpt = my_getnbr(nbr);
  free(nbr);
  return (cpt);
}

static void	cute_error(int testy, int y_file, int x_file, int wrong)
{
  if (wrong == 1)
    {
      my_printf("bad character in the file.\n");
      exit(0);
    }
  if (wrong == 2)
    {
      my_printf("different spotted size of line.\n");
      exit(0);
    }
  if (testy != y_file)
    {
      my_printf("incompatible number of lines.\n");
      exit(0);
    }
  if (x_file < 1)
    {
      my_printf("too short size line.\n");
      exit(0);
    }
}

static int	cute_x(char *buff, int i, int y_file, int wrong)
{
  int		x_file;
  int		testy;
  int		testx;

  x_file = -1;
  testy = 0;
  testx = 0;
  while (buff[++i])
    {
      if (buff[i] != '.' && buff[i] != 'o' && buff[i] != '\n')
	wrong = 1;
      testx += (buff[i] == '.' || buff[i] == 'o') ? 1 : 0;
      if (buff[i] == '\n')
	{
	  x_file = (x_file == -1) ? testx : x_file;
	  if (testx != x_file)
	    wrong = 2;
	  testy++;
	  testx = 0;
	}
    }
  cute_error(testy, y_file, x_file, wrong);
  return (x_file);
}

static void	cute_tab(t_file *f)
{
  f->tab[f->j] = malloc(f->x_file * sizeof(**f->tab));
  if (f->tab[f->j] == NULL)
    exit(0);
  while (f->i < f->x_file)
    {
      if (f->buff[f->bufi] == '.')
	f->tab[f->j][f->i] = 0;
      if (f->buff[f->bufi] == 'o')
	f->tab[f->j][f->i] = -1;
      f->i++;
      f->bufi++;
    }
}

void	my_str_to_wordtab_bsq(t_file *f)
{
  f->i = -1;
  f->j = 0;
  f->bufi = -1;
  f->wrong = -1;
  f->y_file = cute_y(f->buff);
  while (f->buff[++f->bufi] != '\n');
  f->x_file = cute_x(f->buff, f->bufi, f->y_file, f->wrong);
  f->tab = malloc(f->y_file * sizeof(*f->tab));
  (f->tab == NULL) ? exit(0) : 1;
  while (f->j < f->y_file)
    {
      cute_tab(f);
      f->bufi++;
      f->j++;
      f->i = 0;
    }
}
