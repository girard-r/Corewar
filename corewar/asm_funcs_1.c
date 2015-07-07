/*
** asm_funcs.c for corewar in /home/vadee_s/rendu/CPE_2014_corewar/corewar
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Wed Apr  2 10:02:13 2014 vadee
** Last update Sun Apr 13 21:41:27 2014 vadee
*/

#include <stdlib.h>
#include "union.h"
#include "op.h"
#include "corewar.h"

int		live(t_param *param, t_champion *champ, char *arena)
{
  my_putstr("Le joueur ");
  my_putstr(champ->name);
  my_putstr(" est en vie\n");
  champ->live = 1;
  return (0);
}

int		ld(t_param *param, t_champion *champ, char *arena)
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

int		st(t_param *param, t_champion *champ, char *arena)
{
  union u_int	val;
  int		pos;

  if (param->param[0][1] != REGISTRE
      || param->param[1][1] == DIRECT)
    return (0);
  if (param->param[1][1] == REGISTRE && param->param[1][0] >= 0
	   && param->param[1][0] < 16)
    champ->r[param->param[1][0]] = champ->r[param->param[0][0]];
  else if (param->param[1][1] == INDIRECT)
    {
      val.nb = param->param[0][0];
      pos = champ->pc + (param->param[1][0] % IDX_MOD);
      arena[pos % MEM_SIZE] = val.ch[0];
      arena[(pos + 1) % MEM_SIZE] = val.ch[1];
      arena[(pos + 2) % MEM_SIZE] = val.ch[2];
      arena[(pos + 3) % MEM_SIZE] = val.ch[3];
    }
  return (1);
}

int		add(t_param *param, t_champion *champ, char *arena)
{
  if (param->param[0][0] >= 0 && param->param[0][0] < 16
      && param->param[1][0] >= 0 && param->param[1][0] < 16
      && param->param[2][0] >= 0 && param->param[2][0] < 16)
    champ->r[param->param[2][0]] =
      champ->r[param->param[0][0]] + champ->r[param->param[1][0]];
  return (1);
}

int		sub(t_param *param, t_champion *champ, char *arena)
{
  if (param->param[0][0] >= 0 && param->param[0][0] < 16
      && param->param[1][0] >= 0 && param->param[1][0] < 16
      && param->param[2][0] >= 0 && param->param[2][0] < 16)
  champ->r[param->param[2][0]] =
    champ->r[param->param[0][0]] - champ->r[param->param[1][0]];
  return (1);
}
