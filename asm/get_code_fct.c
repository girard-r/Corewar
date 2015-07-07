/*
** get_code_fct.c for corewar in /home/menigo_m/rendu/Corewar/corewar
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Thu Apr 10 10:27:41 2014 a
** Last update Thu Apr 10 10:51:55 2014 a
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"

char	get_fct(char *name)
{
  int	i;

  if (name == NULL)
    return (0);
  i = 0;
  while (op_tab[i].mnemonique != 0 &&
	 my_strcmp(op_tab[i].mnemonique, name) != 0)
    i = i + 1;
  if (op_tab[i].mnemonique != 0)
    return (op_tab[i].code);
  my_putstr("Unknown mnemonic : ");
  my_putstr(name);
  my_putchar(10);
  exit(EXIT_FAILURE);
}

char	complete_code(char result, int i, int decal)
{
  while (i < MAX_ARGS_NUMBER + decal - 1)
    {
      result = result << 2;
      i = i + 1;
    }
  return (result);
}

int	find_decal(char **tab)
{
  int	decal;

  decal = 0;
  if (end_cmp(get_lab_char(2), tab[decal]) == 0)
    decal = decal + 1;
  decal = decal + 1;
  return (decal);
}

char	type_args(char *arg, char type[MAX_ARGS_NUMBER], int i)
{
  if (*arg == '\\')
    arg = arg + 1;
  if (*arg == 'r')
    {
      type[i] = 1;
      return (1);
    }
  else if (*arg == DIRECT_CHAR)
    {
      type[i] = 2;
      return (2);
    }
  else
    {
      type[i] = 3;
      return (3);
    }
}

char	get_code(char **tab, char fct, char type[MAX_ARGS_NUMBER], char *line)
{
  int	i;
  int	y;
  int	decal;
  char	result;

  result = 0;
  decal = find_decal(tab);
  i = decal;
  while (tab[i] && i < MAX_ARGS_NUMBER + decal - 1)
    {
      result = result | type_args(tab[i], type, i - decal);
      if (i != MAX_ARGS_NUMBER + decal - 1)
	result = result << 2;
      i = i + 1;
    }
  type[i - decal] = '\0';
  y = 0;
  while (op_tab[y].code != fct)
    y = y + 1;
  if (op_tab[y].nbr_args != i - decal || tab[i] != NULL)
    exit_error("Invalid number of arguments : \n\t", line, 0);
  result = complete_code(result, i, decal);
  return (result);
}
