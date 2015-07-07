/*
** instructions.c for instructions in /home/lopes_n/rendu/corewar/header
** 
** Made by lopes_n
** Login   <lopes_n@epitech.net>
** 
** Started on  Thu Mar 20 14:40:55 2014 lopes_n
** Last update Thu Apr 10 10:31:24 2014 a
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"
#include "get_next_line.h"

int	verif_endian(void)
{
  int	i;

  i = 1;
  if ((char)i == 1)
    return (1);
  return (0);
}

char	*get_lab_char(int size)
{
  char	*lab;

  lab = malloc(sizeof(char) * size);
  if (lab == NULL)
    exit_error("Malloc of get_lab_char failed\n", "", 0);
  if (size == 2)
    {
      lab[0] = LABEL_CHAR;
      lab[1] = '\0';
    }
  else if (size == 3)
    {
      lab[0] = DIRECT_CHAR;
      lab[1] = LABEL_CHAR;
      lab[2] = '\0';
    }
  return (lab);
}

void	verif_arg(char type[MAX_ARGS_NUMBER], char fct)
{
  int	i;
  int	y;

  i = 0;
  while (op_tab[i].code != 0 && op_tab[i].code != fct)
    i = i + 1;
  if (op_tab[i].code != 0)
    {
      y = 0;
      while (op_tab[i].type[y] && y < MAX_ARGS_NUMBER)
	{
	  if ((type[y] & op_tab[i].type[y]) == 0)
	    {
	      my_putstr("Mauvais type d'argument\n");
	      exit(EXIT_FAILURE);
	    }
	  y = y + 1;
	}
    }
}

char	parse_line(char *line, t_elem *datas, t_label *label, int size)
{
  char	**tab;
  char	fct;
  int	i;

  i = 0;
  line = epur_str(line);
  if ((tab = my_str_to_wordtab(line)) == NULL)
    exit_error("Malloc of my_str_to_wordtab failed\n", "", 0);
  if (tab[i] && end_cmp(get_lab_char(2), tab[i]) == 0)
    i = i + 1;
  if ((fct = get_fct(tab[i])) == 0)
    return (0);
  datas->code = get_code(tab, fct, datas->type, line);
  verif_arg(datas->type, fct);
  get_params(tab, datas->params, label, size);
  return (fct);
}

t_instru	*put_instruction(int fd, t_instru *instruction,
				 int *size, t_label *label)
{
  t_elem	datas;
  char		*line;

  while ((line = get_next_line(fd)) != NULL)
    {
      if (is_comment(line) != 0 && is_empty(line) != 0)
	{
	  if ((datas.fct = parse_line(line, &datas, label, *size)) != 0)
	    {
	      my_put_in_list(&instruction, datas);
	      *size = *size + get_size(instruction->next);
	    }
	}
    }
  return (instruction);
}
