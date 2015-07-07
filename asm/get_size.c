/*
** get_size.c for corewar in /home/menigo_m/rendu/Corewar/corewar
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Thu Apr 10 10:41:35 2014 a
** Last update Thu Apr 10 10:52:59 2014 a
*/

#include "op.h"
#include "asm.h"

int	get_size(t_instru *instruction)
{
  int	i;
  int	y;

  i = 1;
  if (instruction->code != 9 && instruction->code != 1 &&
      instruction->code != 12 && instruction->code != 15)
    i = i + 1;
  y = 0;
  while (y < get_nbr_args(instruction->code))
    {
      if (instruction->type[y] == 1)
	i = i + 1;
      else if (instruction->type[y] == 2 && is_ind(instruction->code) == 0)
	i = i + 4;
      else
	i = i + 2;
      y = y + 1;
    }
  return (i);
}
