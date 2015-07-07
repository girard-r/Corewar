/*
** trunc.c for corewar in /home/vadee_s/rendu/CPE_2014_corewar/corewar
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Mon Apr  7 11:46:39 2014 vadee
** Last update Sun Apr 13 21:05:20 2014 vadee
*/

#include <stdlib.h>
#include <stdio.h>
#include "op.h"
#include "corewar.h"
#include "union.h"

int		process_test_opcode(char *arena, t_champion **tmp, int i)
{
  t_param	*param;

  if ((param = malloc(sizeof(t_param))) == NULL)
    return (-1);
  if (g_func[i].opcode != 0)
    {
      (*tmp)->cycle_max = g_func[i].cycle;
      get_param(param, tmp, arena, i);
      (*tmp)->carry = g_func[i].ptrf(param, *tmp, arena);
    }
  else
    {
      (*tmp)->pc += 1;
      if ((*tmp)->pc >= MEM_SIZE - 1)
	(*tmp)->pc = 0;
    }
  return (0);
}

int		loop_champ(char *arena, t_champion *champ, int *nb_champ)
{
  int		i;
  t_champion	*tmp;

  tmp = champ->next;
  while (tmp->name != NULL)
    {
      if (tmp->cycle_max == 0 && tmp->rank == 0)
      	{
      	  i = 0;
	  if (tmp->pc < MEM_SIZE && tmp->pc >= 0)
	    while (i < 16 && ((int)arena[tmp->pc] != g_func[i].opcode))
	      i = i + 1;
	  if (g_func[i].opcode == 0x0c || g_func[i].opcode == 0x0f)
	    *nb_champ += 1;
	  if (process_test_opcode(arena, &tmp, i) == -1)
      	    return (-1);
        }
      else
	tmp->cycle_max -= 1;
      tmp = tmp->next;
    }
  tmp = tmp->next;
  return (0);
}

int		loop_cycle_to_die(char *arena, t_champion *champ,
				  int *nb_champ, int lower)
{
  int		i;
  static int	cycle_to_die = CYCLE_TO_DIE;
  int		nbr_live;

  i = 0;
  cycle_to_die -= lower;
  if (cycle_to_die <= 0)
    {
      printf("NO WINNER\n");
      return (-1);
    }
  while (i < cycle_to_die)
    {
      if (loop_champ(arena, champ, nb_champ) == -1)
	return (-1);
      i += 1;
    }
  if (check_live(champ, nb_champ) == -1)
    return (-1);
  return (0);
}

int		loop_nb_champ(char *arena, t_champion *champ,
			      int *nb_champ, long nbr_cycle)
{
  long		i;
  int		nbr_alive;
  int		lower;

  i = 0;
  check_alive(champ, *nb_champ, &nbr_alive, &lower);
  while (*nb_champ > 1 && i++ < nbr_cycle)
    {
      if (loop_cycle_to_die(arena, champ, nb_champ, lower) == -1)
	return (-1);
      if (check_alive(champ, *nb_champ, &nbr_alive, &lower) == 0)
      	nbr_alive += 1;
      else
      	nbr_alive = 0;
      if (nbr_alive == NBR_LIVE)
      	{
      	  lower = CYCLE_DELTA;
      	  nbr_alive = 0;
      	}
      else
      	lower = 0;
    }
  ranking(champ);
  return (0);
}
