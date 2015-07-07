/*
** print_ins.c for print_ins in /home/lopes_n/rendu/corewar/header
** 
** Made by lopes_n
** Login   <lopes_n@epitech.net>
** 
** Started on  Wed Mar 26 18:16:56 2014 lopes_n
** Last update Thu Apr 10 15:14:03 2014 a
*/

#include <unistd.h>
#include <fcntl.h>
#include "op.h"
#include "asm.h"

int		is_ind(char code)
{
  if (code >= 9 && code <= 15 && code != 13)
    return (1);
  else
    return (0);
}

void		print_ins(t_instru *instruction, int fd)
{
  write(fd, &(instruction->code), 1);
  if (instruction->code != 9 && instruction->code != 1 &&
      instruction->code != 12 && instruction->code != 15)
    write(fd, &(instruction->params), 1);
  print_values(instruction, fd);
}

void		print_in_file(char *name, header_t *header,
			      t_instru *instruction, int size)
{
  int		fd;
  t_instru	*tmp;

  fd = open(check_wr_name(name), O_WRONLY | O_CREAT | O_TRUNC,
	    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (fd < 0)
    exit_error("Error while printing in file\n", "", 0);
  if (verif_endian() == 1)
    header->prog_size = INVERT_ENDIAN(size);
  write(fd, header, sizeof(*header));
  tmp = instruction->prev;
  while (tmp != instruction)
    {
      print_ins(tmp, fd);
      tmp = tmp->prev;
    }
  close(fd);
}
