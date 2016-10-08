/*
** my_sort_int_tab.c for  in /home/belfio_u/PISCINE/rendu/Piscine_C_J04
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sun Oct  5 14:32:21 2014 ugo belfiore
** Last update Thu Nov  6 19:36:37 2014 ugo belfiore
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	again;

  i = 0;
  again = 0;
  while (again == 0)
    {
      i = 0;
      again = 1;
      while (i < size)
	{
	  if (tab[i] > tab[i + 1]) 
	    {
	      again = 0;
	      my_swap(&tab[i], &tab[i + 1]);
	    }
	  i++;
	}
    }
}
