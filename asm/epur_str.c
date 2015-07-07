/*
** epur_str.c for epur_str in /home/lopes_n/rendu/corewar
** 
** Made by lopes_n
** Login   <lopes_n@epitech.net>
** 
** Started on  Mon Mar 17 17:35:25 2014 lopes_n
** Last update Thu Apr 10 10:49:24 2014 a
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"

int	calcul_size(char *str)
{
  int	nb_space;
  int	nb_letter;
  int	i;

  i = 0;
  nb_space = 0;
  nb_letter = 0;
  while (str[i] != '\0' && str[i] != ';' && str[i] != COMMENT_CHAR)
    {
      if (i != 0 && (str[i] == ' ' || str[i] == '\t') &&
	  (str[i - 1] != ' ' && str[i - 1] != '\t'))
	nb_space = nb_space + 1;
      if (str[i] != ' ' && str[i] != '\t')
	nb_letter = nb_letter + 1;
      i = i + 1;
    }
  return (nb_letter + nb_space);
}

char	*epur_str(char *str)
{
  char	*epur;
  int	y;
  int	i;
  int	size;

  size = calcul_size(str);
  epur = malloc(sizeof(char) * (size + 1));
  if (epur == NULL)
    exit_error("Malloc of epur_str failed\n", "", 0);
  i = 0;
  y = 0;
  while (str[i] != '\0' && str[i] != ';' && str[i] != COMMENT_CHAR)
    {
      if (y != 0 && i != 0 && str[i] != ' ' && str[i] != '\t' &&
	  (str[i - 1] == ' ' || str[i - 1] == '\t'))
	{
	  epur[y++] = ' ';
	  epur[y++] = str[i];
	}
      else if (str[i] != ' ' && str[i] != '\t')
	epur[y++] = str[i];
      i = i + 1;
    }
  epur[y] = '\0';
  return (epur);
}
