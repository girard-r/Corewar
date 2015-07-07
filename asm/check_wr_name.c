/*
** check_wr_name.c for corewar in /home/menigo_m/rendu/Corewar/corewar
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Thu Apr 10 10:37:28 2014 a
** Last update Thu Apr 10 10:51:56 2014 a
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"

char	*del_ext(char *name)
{
  int	i;
  char	*out;

  i = 0;
  while (name[i] && name[i] != '.')
    i = i + 1;
  out = malloc(sizeof(char) * (i + 1));
  if (out == NULL)
    exit_error("Malloc of del_ext failed\n", "", 0);
  i = 0;
  while (name[i] && name[i] != '.')
    {
      out[i] = name[i];
      i = i + 1;
    }
  out[i] = '\0';
  return (out);
}

int	no_ext(char *name)
{
  int	i;

  i = 0;
  while (name[i])
    {
      if (name[i] == '.')
	return (-1);
      i = i + 1;
    }
  return (0);
}

char	*check_wr_name(char *name)
{
  char	*out;

  if (end_cmp(".s", name) != 0 && no_ext(name) != 0)
    {
      my_putstr("Error : invalid file\n");
      exit(EXIT_FAILURE);
    }
  name = del_ext(name);
  out = malloc(sizeof(char) * (my_strlen(name) + 5));
  if (out == NULL)
    exit_error("Malloc of check_wr_name failed\n", "", 0);
  my_strcpy(out, name);
  my_strcat(out, ".cor");
  return (out);
}
