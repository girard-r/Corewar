/*
** asm_funcs_4.c for asm_funcs_4.c in /home/girard_r/Documents/Corewar/vm
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sun Apr 13 19:57:21 2014 girard_r
** Last update Sun Apr 13 21:28:48 2014 vadee
*/

#include <stdlib.h>
#include "union.h"
#include "op.h"
#include "corewar.h"

int		lld(t_param *param, t_champion *champ, char *arena)
{
  if (param->param[0][1] == REGISTRE
      || param->param[1][1] != REGISTRE)
    return (0);
  else if (param->param[0][1] == DIRECT && param->param[1][0] >= 0
	   && param->param[1][0] < 16)
    champ->r[param->param[1][0]] = param->param[0][0];
  else if (param->param[0][1] == INDIRECT && param->param[1][0] >= 0
	   && param->param[1][0] < 16)
    champ->r[param->param[1][0]] = param->param[0][0];
  return (1);
}

int		lldi(t_param *param, t_champion *champ, char *arena)
{
  return (1);
}

int		my_lfork(t_param *param, t_champion *champ, char *arena)
{
  if (param->param[0][0] < MEM_SIZE && param->param[0][0] >= 0)
    {
      store_in_list(&champ, champ->pc + (param->param[0][0]));
      champ->prev->name = champ->name;
      champ->prev->rank = champ->rank;
      champ->prev->son = champ->son + 1;
      champ->pc += 3;
    }
  else
    return (0);
  return (1);
}

int		aff(t_param *param, t_champion *champ, char *arena)
{
  my_putchar(champ->r[param->param[0][0]] % 256);
  return (1);
}
