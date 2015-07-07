/*
** main.c for corewar in /home/vadee_s/rendu/CPE_2014_corewar/corewar
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Thu Mar 27 14:44:54 2014 vadee
** Last update Sun Apr 13 21:34:31 2014 vadee
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "corewar.h"
#include "op.h"
#include "Parsing/parsing.h"

void		my_show_mem(char *str, int size)
{
  int		i;
  int		j;

  j = 0;
  i = size;
  while (i != 0)
    {
      if (str[j] == 0)
	my_putchar('0');
      else
	my_putchar('1');
      j = j + 1;
      --i;
    }
}

void		display_error_magic(int player)
{
  my_putstr("player ");
  my_putnbr(player);
  my_putstr("is invalid, please re-check the COREWAR_EXEC_MAGIC\n");
}

int		check_exec_magic(char *arena, t_champion *champ)
{
  int		i;
  unsigned char buffer[129];
  int		j;

  j = 1;
  while (champ->next->name != NULL)
    {
      i = -1;
      while (++i != 4)
	buffer[i] = arena[champ->next->pc + i];
      if (buffer[0] != 0 || buffer[1] != 234
	  || buffer[2] != 131 || buffer[3] != 243)
	{
	  display_error_magic(j);
	  return (-1);
	}
      j = 0;
      while (i != 128)
	buffer[j++] = arena[champ->next->pc + i++];
      champ->next->name = my_strdup_uns(buffer);
      champ->next->pc = champ->next->pc + sizeof(header_t);
      champ = champ->next;
    }
  champ = champ->next;
  return (0);
}

int		main(int argc, char **argv)
{
  char		*arena;
  t_champion	*champ;
  t_info	parse;
  int		total;

  total = 0;
  if (parsing(argc, argv, &parse) == -1
      || init_list(&champ) == -1
      || (arena = malloc(sizeof(char) * MEM_SIZE)) == NULL)
    return (-1);
  clean_buffer(arena);
  if (determ_champ_pos(parse.prog_name, &total) == -1
      || set_champ_in_mem(parse.prog_name,
			  ((MEM_SIZE - total) / parse.nb_champ), arena, champ) == -1
      || check_exec_magic(arena, champ) == -1
      || loop_nb_champ(arena, champ, &parse.nb_champ, parse.nbr_cycle) == -1)
    return (-1);
  free(arena);
  free(champ);
  return (0);
}
