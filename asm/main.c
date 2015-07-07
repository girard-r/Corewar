/*
** test.c for test in /home/lopes_n/rendu/corewar
** 
** Made by lopes_n
** Login   <lopes_n@epitech.net>
** 
** Started on  Wed Mar  5 09:08:41 2014 lopes_n
** Last update Fri Apr 11 10:55:30 2014 a
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "op.h"
#include "asm.h"

char		get_nbr_args(char code)
{
  int		i;

  i = 0;
  while (op_tab[i].code != 0 && op_tab[i].code != code)
    i = i + 1;
  return (op_tab[i].nbr_args);
}

int		open_file(char *name)
{
  int		fd;

  check_wr_name(name);
  fd = open(name, O_RDONLY);
  if (fd < 0)
    {
      my_putstr("Error during opening the file\n");
      return (-1);
    }
  return (fd);
}

void		display_champ(header_t *header, char *name)
{
  my_putstr("File ");
  if (name != NULL)
    my_putstr(name);
  my_putstr(" assembled :\n");
  my_putstr("\t\tName = ");
  if (header->prog_name != NULL)
    my_putstr(header->prog_name);
  my_putchar(10);
  my_putstr("\t\tComment = ");
  if (header->comment != NULL)
    my_putstr(header->comment);
  my_putchar(10);
  my_putstr("Enjoy the war !\n\n");
}

int		fill_struct(char *name, header_t *header, t_instru *instruction)
{
  int		fd;
  int		size;
  t_label	*label;
  int		line_nbr;

  label = NULL;
  line_nbr = 1;
  size = 0;
  fd = open_file(name);
  if (fd < 0)
    return (-1);
  if (put_header(fd, header, &line_nbr) == -1)
    return (-2);
  label = get_label(fd, label, &line_nbr);
  close(fd);
  fd = open_file(name);
  if (fd < 0)
    return (-1);
  if (put_header(fd, header, &line_nbr) == -1)
    return (-2);
  instruction = put_instruction(fd, instruction, &size, label);
  close(fd);
  display_champ(header, name);
  return (size);
}

int		main(int argc, char **argv)
{
  header_t	header;
  int		i;
  int		size;
  t_instru	*instruction;

  init_header(&header);
  i = 1;
  if (argc == 1)
    my_putstr("Please choose a champ (.s) to use the asm\n");
  while (i < argc)
    {
      if ((instruction = list_init_instru()) == NULL)
	return (-1);
      if (instruction == NULL)
	return (-1);
      if ((size = fill_struct(argv[i], &header, instruction)) < 0)
	{
	  if (size == -1)
	    my_putstr("Error on opening file\n");
	  return (-1);
	}
      print_in_file(argv[i], &header, instruction, size);
      i = i + 1;
    }
  return (0);
}
