/*
** basic_funcs.c for corewar in /home/vadee_s/rendu/CPE_2014_corewar/corewar
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Thu Mar 27 15:14:23 2014 vadee
** Last update Sun Apr 13 21:39:16 2014 vadee
*/

#include <stdlib.h>
#include "op.h"
#include "corewar.h"

char		*my_strdup(char *src)
{
  int		i;
  char		*dest;

  i = 0;
  dest = malloc(my_strlen(src) + 1);
  if (dest == NULL)
    return (NULL);
  while (src[i] != 0)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

void		clean_buffer(char *buffer)
{
  int		i;

  i = 0;
  while (i != MEM_SIZE)
    buffer[i++] = 0;
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i++]);
  write(1, str, i - 1);
}

void		my_putchar(char c)
{
  write (1, &c, 1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i++]);
  return (i - 1);
}
