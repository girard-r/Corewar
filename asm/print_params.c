/*
** print_params.c for corewar in /home/menigo_m/rendu/Corewar/corewar
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Thu Apr 10 10:42:22 2014 a
** Last update Thu Apr 10 10:56:30 2014 a
*/

#include <unistd.h>
#include "op.h"
#include "asm.h"

void		print_char(int value, int fd)
{
  char		tmp;

  tmp = (char)value;
  write(fd, &tmp, 1);
}

void		print_int(int value, int fd)
{
  if (verif_endian() == 1)
    value = INVERT_ENDIAN(value);
  write(fd, &(value), 4);
}

void		print_short_int(int value, int fd)
{
  short int	tmp;

  tmp = (short int)value;
  if (verif_endian() == 1)
    tmp = INVERT_ENDIAN_SHORT(tmp);
  write(fd, &tmp, 2);
}

void		print_values(t_instru *instruction, int fd)
{
  int		y;

  y = 0;
  while (y < get_nbr_args(instruction->code))
    {
      if (instruction->type[y] == 1)
	print_char(instruction->value[y], fd);
      else if (instruction->type[y] == 2 && is_ind(instruction->code) == 0)
	print_int(instruction->value[y], fd);
      else
	print_short_int(instruction->value[y], fd);
      y = y + 1;
    }
}
