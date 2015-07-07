/*
** my_lists.c for corewar in /home/vadee_s/rendu/CPE_2014_corewar/corewar
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Fri Mar 28 17:42:33 2014 vadee
** Last update Fri Apr 11 23:08:01 2014 vadee
*/

#include <stdlib.h>
#include "corewar.h"

int		store_in_list(t_champion **champ, int pos)
{
  t_champion	*elem;
  static int	i = 1;
  int		j;

  j = 1;
  elem = malloc(sizeof(t_champion));
  if (elem == NULL)
    return (-1);
  elem->pc = pos;
  elem->r[0] = i++;
  elem->live = 0;
  while (j != 16)
    elem->r[j++] = 0;
  elem->cycle_max = 0;
  elem->son = 0;
  elem->rank = 0;
  elem->name = my_strdup("none");
  elem->prev = (*champ)->prev;
  elem->next = *champ;
  (*champ)->prev->next = elem;
  (*champ)->prev = elem;
  return (0);
}

int		init_list(t_champion **champ)
{
  if (((*champ) = malloc(sizeof(t_champion))) == NULL)
    return (-1);
  (*champ)->next = *champ;
  (*champ)->prev = *champ;
  (*champ)->name = NULL;
  return (0);
}
