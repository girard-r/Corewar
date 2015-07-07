/*
** get_param1.c for corewar in /home/vadee_s/rendu/CPE_2014_corewar/vm
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Sun Apr 13 20:20:58 2014 vadee
** Last update Sun Apr 13 20:35:26 2014 vadee
*/

#include "stdlib.h"
#include "corewar.h"
#include "union.h"
#include "op.h"

void		get_param_5(t_param *param, char bitcode, int *j, int l)
{
  int		k;

  k = ((bitcode >> *j) & 1) * 10;
  *j -= 1;
  k = k + ((bitcode >> *j) & 1);
  *j -= 1;
 if (k == 1)
    param->param[l][1] = REGISTRE;
  else if (k == 10)
    param->param[l][1] = DIRECT;
  else if (k == 11)
    param->param[l][1] = INDIRECT;
  else
    param->param[l][1] = 0;
}

void		get_param(t_param *param, t_champion **champ, char *arena, int i)
{
  char		bitcode;
  int		j;
  int		l;
  int		k;

  l = -1;
  j = 7;
  if (g_func[i].bitcode == -1)
    {
      (*champ)->pc += 1;
      bitcode = (int)arena[(*champ)->pc];
    }
  else
    bitcode = g_func[i].bitcode;
  while (j >= 0 && ++l != 3)
    get_param_5(param, bitcode, &j, l);
  get_param_1(param, *champ, arena, i);
}
