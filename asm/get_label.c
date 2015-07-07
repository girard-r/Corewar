/*
** get_label.c for corewar in /home/menigo_m/rendu/Corewar/header
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Mon Mar 31 12:11:33 2014 a
** Last update Fri Apr 11 10:55:56 2014 a
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"
#include "get_next_line.h"

t_label		*parse_label(char *line, t_elem datas,
			     t_label *label, int *size)
{
  char		**tab;
  char		fct;
  int		i;

  i = 0;
  line = epur_str(line);
  if ((tab = my_str_to_wordtab(line)) == NULL)
    exit_error("Malloc of my_str_to_wordtab failed\n", "", 0);
  if (tab[i] && end_cmp(get_lab_char(2), tab[i]) == 0)
    {
      if (is_in_str(tab[i]) != 0)
	exit_error("Wrong label name : ", tab[i], 0);
      my_put_in_label(&label, tab[i], *size);
      i = i + 1;
    }
  if (tab[i + 1] == NULL)
    return (label);
  fct = get_fct_label(tab[i], datas.line_nbr, line);
  get_args_label(tab, datas.type, datas.line_nbr, line);
  get_params_label(tab, datas.params);
  *size = *size + get_size_label(fct, datas.type);
  return (label);
}

t_label		*get_label(int fd, t_label *label, int *line_nbr)
{
  int		size;
  char		*line;
  t_elem	datas;

  datas.line_nbr = *line_nbr;
  size = 0;
  while ((line = get_next_line(fd)) != NULL)
    {
      *line_nbr = *line_nbr + 1;
      if (is_comment(line) != 0 && is_empty(line) != 0)
	label = parse_label(line, datas, label, &size);
    }
  return (label);
}
