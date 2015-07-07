/*
** check_header.c for corewar in /home/menigo_m/rendu/Corewar/corewar
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Thu Apr 10 10:23:45 2014 a
** Last update Thu Apr 10 10:51:56 2014 a
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"

int	is_empty(char *line)
{
  int	i;

  i = 0;
  if (line == NULL)
    return (0);
  while (line[i] != '\0')
    {
      if (line[i] != ' ' && line[i] != '\t')
	return (-1);
      i = i + 1;
    }
  return (0);
}

int	is_comment(char *str)
{
  if (str == NULL)
    return (0);
  if (str[0] == COMMENT_CHAR || str[0] == ';')
    return (0);
  return (1);
}
