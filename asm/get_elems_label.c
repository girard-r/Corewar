/*
** get_elems_label.c for corewar in /home/menigo_m/rendu/Corewar/corewar
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Thu Apr 10 10:45:16 2014 a
** Last update Fri Apr 11 10:50:52 2014 a
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"

int		get_loc(char *name, t_label *label)
{
  t_label	*tmp;
  int		i;

  tmp = label;
  if (*name == DIRECT_CHAR)
    name = name + 1;
  if (*name == LABEL_CHAR)
    name = name + 1;
  while (tmp != NULL)
    {
      i = 0;
      while (tmp->name[i] && tmp->name[i] != LABEL_CHAR)
	{
	  if (is_in_str(name) != 0)
	    exit_error("Wrong label name : ", name, 0);
	  i = i + 1;
	}
      tmp->name[i] = '\0';
      if (my_strcmp(name, tmp->name) == 0)
	return (tmp->loc);
      tmp = tmp->next;
    }
  my_putstr("Error : undefined label\n");
  exit(EXIT_FAILURE);
}

char		get_fct_label(char *name, int line_nbr, char *line)
{
  int		i;

  if (name == NULL)
    return (0);
  i = 0;
  while (op_tab[i].mnemonique != 0 &&
	 my_strcmp(op_tab[i].mnemonique, name) != 0)
    i = i + 1;
  if (op_tab[i].mnemonique != 0)
    return (op_tab[i].code);
  my_putstr("Syntax error line ");
  my_put_nbr(line_nbr);
  my_putstr(":\n\t");
  my_putstr(line);
  my_putchar(10);
  exit(EXIT_FAILURE);
}

void		get_args_label(char **tab, char type[MAX_ARGS_NUMBER],
			       int line_nbr, char *line)
{
  int		i;
  int		decal;

  decal = 0;
  if (tab[decal] && end_cmp(get_lab_char(2), tab[decal]) == 0)
    decal = decal + 1;
  decal = decal + 1;
  i = decal;
  while (tab[i] && i < MAX_ARGS_NUMBER + decal - 1)
    {
      type_args(tab[i], type, i - decal);
      i = i + 1;
    }
  if (tab[i] != NULL)
    {
      my_putstr("Syntax error line ");
      my_put_nbr(line_nbr);
      my_putstr(":\n\t");
      my_putstr(line);
      my_putchar(10);
      exit(EXIT_FAILURE);
    }
  type[i - decal] = '\0';
}

void		get_params_label(char **tab, int params[MAX_ARGS_NUMBER])
{
  int		i;
  int		y;

  y = 0;
  i = 0;
  if (tab[i] && end_cmp(get_lab_char(2), tab[i]) == 0)
    i = i + 1;
  i = i + 1;
  while (tab[i])
    {
      if (start_cmp(get_lab_char(3), tab[i]) == 0 ||
	  start_cmp(get_lab_char(2), tab[i]) == 0)
	params[y] = 0;
      else if (is_nbr(tab[i]) == 1)
	params[y] = my_getnbr_param(tab[i]);
      else
	{
	  my_putstr("Argument is not valid\n");
	  exit(EXIT_FAILURE);
	}
      y = y + 1;
      i = i + 1;
    }
}

int		get_size_label(char code, char type[MAX_ARGS_NUMBER])
{
  int		i;
  int		y;

  i = 1;
  if (code != 9 && code != 1 &&
      code != 12 && code != 15)
    i = i + 1;
  y = 0;
  while (y < get_nbr_args(code))
    {
      if (type[y] == 1)
	i = i + 1;
      else if (type[y] == 2 && is_ind(code) == 0)
	i = i + 4;
      else
	i = i + 2;
      y = y + 1;
    }
  return (i);
}
