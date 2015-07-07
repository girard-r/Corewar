/*
** asm_funcs_3.c for asm_func_3 in /home/girard_r/Documents/Corewar/vm
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sun Apr 13 19:35:22 2014 girard_r
** Last update Sun Apr 13 20:19:45 2014 girard_r
*/

#include <stdlib.h>
#include "union.h"
#include "op.h"
#include "corewar.h"

int		get_ldi_param(t_param *param, t_champion *champ, int *v1, int *v2)
{
  if (param->param[0][1] == REGISTRE)
    *v1 = champ->r[param->param[0][0]];
  else if (param->param[0][1] == DIRECT
	   || param->param[0][1] == INDIRECT)
    *v1 = param->param[0][0];
  if (param->param[1][1] == REGISTRE)
    *v2 = champ->r[param->param[1][0]];
  else if (param->param[1][1] == DIRECT)
    *v2 = param->param[1][0];
  else
    return (0);
  return (1);
}

int		ldi(t_param *param, t_champion *champ, char *arena)
{
  int		v1;
  int		v2;
  int		pos;
  union u_int	u_int;

  v1 = 0;
  v2 = 0;
  if (get_ldi_param(param, champ, &v1, &v2) == 0)
    return (0);
  pos = champ->pc + ((v1 + v2) % IDX_MOD);
  if (pos >= MEM_SIZE || pos < 0)
    return (0);
  u_int.ch[0] = arena[pos];
  u_int.ch[1] = arena[pos + 1];
  u_int.ch[2] = arena[pos + 2];
  u_int.ch[3] = arena[pos + 3];
  if (param->param[2][1] == REGISTRE && param->param[2][0] < 16)
    champ->r[param->param[2][0]] = u_int.nb;
  else
    return (0);
  return (1);
}

int		get_sti_param(t_param *param, t_champion *champ, int *v1, int *v2)
{
  *v1 = 0;
  *v2 = 0;
  if (param->param[0][1] != REGISTRE)
    return (0);
  if (param->param[1][1] == REGISTRE)
    *v1 = champ->r[param->param[1][0]];
  else if (param->param[1][1] == DIRECT
	   || param->param[1][1] == INDIRECT)
    *v1 = param->param[1][0];
  if (param->param[2][1] == REGISTRE)
    *v2 = champ->r[param->param[2][0]];
  else if (param->param[2][1] == DIRECT)
    *v2 = param->param[2][0];
  else
    return (0);
  return (1);
}

int		sti(t_param *param, t_champion *champ, char *arena)
{
  union	u_int	val;
  int		v1;
  int		v2;
  int		pos;
  char		buffer[5];

  if (get_sti_param(param, champ, &v1, &v2) == 0)
    return (0);
  val.nb = param->param[0][0];
  pos = v1 + v2;
  if (pos >= MEM_SIZE || pos < 0)
    return (0);
  arena[pos] = val.ch[0];
  arena[pos + 1] = val.ch[1];
  arena[pos + 2] = val.ch[2];
  arena[pos + 3] = val.ch[3];
  return (1);
}

int		my_fork(t_param *param, t_champion *champ, char *arena)
{
  store_in_list(&champ, champ->pc + (param->param[0][0] % IDX_MOD));
  champ->prev->name = champ->name;
  champ->prev->rank = champ->rank;
  champ->prev->son = champ->son + 1;
  champ->pc += 3;
  return (1);
}
