/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/lopes_n/rendu/fdf/image
** 
** Made by lopes_n
** Login   <lopes_n@epitech.net>
** 
** Started on  Sat Dec  7 13:56:05 2013 lopes_n
** Last update Tue Apr  8 14:51:22 2014 a
*/

#include <stdlib.h>
#include "op.h"

int	nbr_word(char *str)
{
  int	out;
  int	i;

  i = 0;
  out = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == SEPARATOR_CHAR ||
	  str[i] == '\n' || str[i] == '\t' || str[i] == '\0')
	i = i + 1;
      else
	{
	  out = out + 1;
	  while (str[i] != '\n' && str[i] != ' ' &&
		 str[i] != SEPARATOR_CHAR && str[i] != '\0' &&
		 str[i] != '\t')
	    i = i + 1;
	}
    }
  return (out);
}

int	malloc_word(char *str, int i)
{
  int	j;

  j = 1;
  i = i + 1;
  while (str[i] != ' ' && str[i] != SEPARATOR_CHAR
	 && str[i] != '\0' && str[i] != '\n' && str[i] != '\t')
    {
      i = i + 1;
      j = j + 1;
    }
  return (j + 1);
}

void	put_nbr_in_tab(int *y, int *i, char *str, char **output)
{
  int	z;

  z = 0;
  output[*y][z] = str[*i];
  *i = *i + 1;
  z = z + 1;
  while (str[*i] != ' ' && str[*i] != SEPARATOR_CHAR &&
	 str[*i] != '\0' && str[*i] != '\n' && str[*i] != '\t')
    {
      output[*y][z] = str[*i];
      *i = *i + 1;
      z = z + 1;
    }
  output[*y][z] = '\0';
  *y = *y + 1;
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	y;
  char	**output;

  output = malloc(sizeof(char *) * (nbr_word(str) + 1));
  if (output == NULL)
    return (NULL);
  y = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == SEPARATOR_CHAR ||
	  str[i] == '\n' || str[i] == '\t')
	i = i + 1;
      else
	{
	  output[y] = malloc(sizeof(char) * malloc_word(str, i));
	  if (output[y] == NULL)
	    return (NULL);
	  put_nbr_in_tab(&y, &i, str, output);
	}
    }
  output[y] = NULL;
  return (output);
}
