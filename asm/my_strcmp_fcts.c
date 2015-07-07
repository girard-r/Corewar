/*
** my_strcmp_fcts.c for corewar in /home/menigo_m/rendu/Corewar/corewar
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Thu Apr 10 10:21:26 2014 a
** Last update Thu Apr 10 10:51:52 2014 a
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"

int	start_cmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  str2 = epur_str(str2);
  while (str1[i] && str2[i])
    {
      if (str1[i] != str2[i])
	return (-1);
      i = i + 1;
    }
  if (str2[i] == '\0' && str1[i] != '\0')
    return (-1);
  return (0);
}

int	end_cmp(char *str1, char *str2)
{
  int	i;
  int	y;

  i = 0;
  y = 0;
  str2 = epur_str(str2);
  while (str1[i])
    i = i + 1;
  while (str2[y])
    y = y + 1;
  while (i >= 0 && y >= 0)
    {
      if (str1[i] != str2[y])
	return (-1);
      i = i - 1;
      y = y - 1;
    }
  if (y < 0 && i >= 0)
    return (-1);
  return (0);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	y;

  i = 0;
  y = 0;
  if (s1 == NULL || s2 == NULL)
    return (1);
  while (s1[i] != '\0' && s2[y] != '\0')
    {
      if (s1[i] == s2[y])
	{
	  i = i + 1;
	  y = y + 1;
	}
      else
	return (s1[i] - s2[y]);
    }
  if (s1[i] == 0 && s2[y] != 0)
    return (-1);
  else if (s1[i] != 0 && s2[y] == 0)
    return (1);
  return (0);
}
