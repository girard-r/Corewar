/*
** exit_error.c for corewar in /home/menigo_m/rendu/Corewar/corewar
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Thu Apr 10 10:47:20 2014 a
** Last update Thu Apr 10 10:51:56 2014 a
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"

void	exit_error(char *str, char *name, int line)
{
  if (str != NULL)
    my_putstr(str);
  if (name != NULL)
    my_putstr(name);
  if (line != 0)
    {
      my_putstr("line");
      my_put_nbr(line);
    }
  my_putchar(10);
  exit(EXIT_FAILURE);
}
