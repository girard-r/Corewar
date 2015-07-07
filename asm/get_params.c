/*
** get_params.c for corewar in /home/menigo_m/rendu/Corewar/corewar
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Thu Apr 10 10:31:13 2014 a
** Last update Thu Apr 10 10:51:54 2014 a
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"

void	get_params(char **tab, int params[MAX_ARGS_NUMBER],
		   t_label *label, int size)
{
  int	i;
  int	y;

  y = 0;
  i = 0;
  if (end_cmp(get_lab_char(2), tab[i]) == 0)
    i = i + 1;
  i = i + 1;
  while (tab[i])
    {
      if (start_cmp(get_lab_char(3), tab[i]) == 0 ||
	  start_cmp(get_lab_char(2), tab[i]) == 0)
	params[y] = get_loc(tab[i], label) - size;
      else if (is_nbr(tab[i]) == 1)
	params[y] = my_getnbr_param(tab[i]);
      else
	{
	  my_putstr("Argument is not valid\n");
	  exit(EXIT_FAILURE);
	}
      i = i + 1;
      y = y + 1;
    }
}
