/*
** is_alive.c for corewar in /home/vadee_s/rendu/CPE_2014_corewar/Repo_git/corewar
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Wed Apr  9 11:32:21 2014 vadee
** Last update Sun Apr 13 21:30:00 2014 vadee
*/

#include <stdlib.h>
#include "corewar.h"

void		ranking(t_champion *champ)
{
  t_champion	*tmp;

  tmp = champ->next;
  while (tmp != champ)
    {
      if (tmp->rank == 1)
	{
	  my_putstr("le joueur ");
	  my_putstr(tmp->name);
	  my_putstr(" GAGNE LA PARTIE !!!!!!!!\n");
	}
      tmp = tmp->next;
    }
}

int		check_live(t_champion *champ, int *nb_champ)
{
  t_champion	*tmp;

  tmp = champ->next;
  while (tmp->name != NULL)
    {
      if (tmp->rank == 0)
      	{
	  if (tmp->live == 0)
	    {
	      tmp->rank = *nb_champ;
	      *nb_champ -= 1;
              if (*nb_champ <= 1)
	      	{
	      	  ranking(champ);
	      	  return (-1);
	      	}
	    }
	  else
	    tmp->live = 0;
	}
      tmp = tmp->next;
    }
  return (0);
}

int		check_alive(t_champion *champ, int nb_champ,
			    int *nbr_alive, int *lower)
{
  static int	i = 0;
  static int	ret = 0;

  if (i++ == 0)
    {
      ret = nb_champ;
      *nbr_alive = 0;
      *lower = 0;
    }
  else if (ret > nb_champ)
    {
      ret = nb_champ;
      return (1);
    }
  return (0);
}
