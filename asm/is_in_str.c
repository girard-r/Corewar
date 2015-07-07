/*
** is_in_str.c for corewar in /home/menigo_m/rendu/Corewar/corewar
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Thu Apr 10 10:33:20 2014 a
** Last update Thu Apr 10 10:51:53 2014 a
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"

int	verif_presence_in_str(char *str, char *verif, int *i)
{
  int	y;
  int	inside;

  while (str[*i] != '\0')
    {
      y = 0;
      inside = 0;
      while (verif[y] != '\0')
	{
	  if (verif[y] == str[*i] || str[*i] == ':')
	    inside = 1;
	  y = y + 1;
	}
      if (inside == 0)
	return (-1);
      *i = *i + 1;
    }
  return (0);
}

int	is_in_str(char *str)
{
  int	i;
  char	*verif;

  if ((verif = malloc(sizeof(char) * (my_strlen(LABEL_CHARS) + 1))) == NULL)
    exit_error("Malloc failed\n", "", 0);
  my_strcpy(verif, LABEL_CHARS);
  verif[my_strlen(LABEL_CHARS)] = '\0';
  i = 0;
  if (str[i] == '%')
    i = i + 1;
  if (str[i] == ':')
    i = i + 1;
  if (verif_presence_in_str(str, verif, &i) == -1)
    return (-1);
  return (0);
}
