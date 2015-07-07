/*
** asm_funcs_2.c for asm_func_2 in /home/girard_r/Documents/Corewar/vm
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sun Apr 13 19:32:46 2014 girard_r
** Last update Sun Apr 13 20:17:40 2014 girard_r
*/

#include <stdlib.h>
#include "union.h"
#include "op.h"
#include "corewar.h"

int		calc_op(t_param *param, t_champion *champ, int op, char *arena)
{
  int		value1;
  int		value2;
  int		i;

  i = 0;
  if (param->param[0][1] == REGISTRE)
    value1 = champ->r[param->param[0][0]];
  else if (param->param[0][1] == DIRECT
	   || param->param[0][1] == INDIRECT)
    value1 = param->param[0][0];
  if (param->param[1][1] == REGISTRE)
    value2 = champ->r[param->param[1][0]];
  else if (param->param[1][1] == DIRECT
	   || param->param[1][1] == INDIRECT)
    value2 = param->param[1][0];
  if (op == 1 && param->param[2][0] >= 0 && param->param[2][0] < 16)
    champ->r[param->param[2][0]] = value1 & value2;
  else if (op == 2 && param->param[2][0] >= 0 && param->param[2][0] < 16)
    champ->r[param->param[2][0]] = value1 | value2;
  else if (op == 3 && param->param[2][0] >= 0 && param->param[2][0] < 16)
    champ->r[param->param[2][0]] = value1 ^ value2;
}

int		and(t_param *param, t_champion *champ, char *arena)
{
  if (param->param[2][1] != REGISTRE)
    return (0);
  calc_op(param, champ, 1, arena);
  return (1);
}

int		or(t_param *param, t_champion *champ, char *arena)
{
  if (param->param[2][1] != REGISTRE)
    return (0);
  calc_op(param, champ, 2, arena);
  return (1);
}

int		xor(t_param *param, t_champion *champ, char *arena)
{
  if (param->param[2][1] != REGISTRE)
    return (0);
  calc_op(param, champ, 3, arena);
  return (1);
}

int		zjump(t_param *param, t_champion *champ, char *arena)
{
  if (champ->carry == 1)
    {
      champ->pc = champ->pc + (param->param[0][0] % IDX_MOD);
    }
  return (1);
}
