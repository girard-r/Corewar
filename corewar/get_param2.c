/*
** get_param2.c for corewar in /home/vadee_s/rendu/CPE_2014_corewar/vm
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Sun Apr 13 20:22:20 2014 vadee
** Last update Sun Apr 13 20:48:08 2014 vadee
*/

#include "stdlib.h"
#include "corewar.h"
#include "union.h"
#include "op.h"

int		get_param_4(t_param *param, t_champion **champ, char *arena, int l)
{
  union u_int	val;
  union u_short	ind;

   if (param->param[l][1] == DIRECT)
    {
      val.ch[0] = arena[(*champ)->pc + 4];
      val.ch[1] = arena[(*champ)->pc + 3];
      val.ch[2] = arena[(*champ)->pc + 2];
      val.ch[3] = arena[(*champ)->pc + 1];
      param->param[l][0] = val.nb;
      (*champ)->pc += 5;
    }
  else if (param->param[l][1] == INDIRECT
	   && arena[(*champ)->pc - 1] == 0x02)
    {
      ind.ch[0] = arena[(*champ)->pc + 2];
      ind.ch[1] = arena[(*champ)->pc + 1];
      param->param[l][0] = ind.nb;
      (*champ)->pc += 2;
    }
}

int		get_param_3(t_param *param, t_champion **champ, char *arena, int i)
{
  int		l;
  union u_int	val;

  l = -1;
  while (++l != 3)
    {
      get_param_4(param, champ, arena, l);
      if (param->param[l][1] == REGISTRE
	  && (*champ)->pc < MEM_SIZE)
	{
	  param->param[l][0] = (int)arena[(*champ)->pc + 1];
	  (*champ)->pc += 2;
	}
      if (param->param[l][1] == INDIRECT
	  && g_func[i].opcode == 0x02)
	{
	  val.ch[0] = arena[(*champ)->pc + 4];
	  val.ch[1] = arena[(*champ)->pc + 3];
	  val.ch[2] = arena[(*champ)->pc + 2];
	  val.ch[3] = arena[(*champ)->pc + 1];
	  param->param[l][0] = val.nb;
	  (*champ)->pc += 5;
	}
    }
}

int		get_param_2(t_param *param, t_champion **champ, char *arena, int i)
{
  union	u_short	ind;

  if ((g_func[i].opcode == 0x09 || g_func[i].opcode == 0x0c
       || g_func[i].opcode == 0x0f)
      && (*champ)->pc < MEM_SIZE)
    {
      if (g_func[i].opcode == 0x09)
	{
	  ind.ch[0] = arena[(*champ)->pc - 1];
	  ind.ch[1] = arena[(*champ)->pc - 2];
	}
      else
	{
	  ind.ch[0] = arena[(*champ)->pc + 2];
	  ind.ch[1] = arena[(*champ)->pc + 1];
	}
      param->param[0][0] = ind.nb;
      if (g_func[i].opcode == 0x09)
	(*champ)->pc += 3;
    }
  else
    {
      if (g_func[i].opcode != 0x01)
	get_param_3(param, champ, arena, i);
    }
}

int		get_param_1(t_param *param, t_champion *champ, char *arena, int i)
{
  union u_int	val;

  if (g_func[i].opcode == 0x01 && champ->pc < MEM_SIZE && champ->pc >= 0)
    {
      val.ch[0] = arena[champ->pc + 4];
      val.ch[1] = arena[champ->pc + 3];
      val.ch[2] = arena[champ->pc + 2];
      val.ch[3] = arena[champ->pc + 1];
      champ->pc += 5;
      param->param[0][0] = val.nb;
    }
  get_param_2(param, &champ, arena, i);
}
