/*
** set_champ_in_mem.c for corewar in /home/vadee_s/rendu/CPE_2014_corewar/corewar
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Fri Mar 28 16:47:39 2014 vadee
** Last update Sun Apr 13 19:16:54 2014 girard_r
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "corewar.h"
#include "op.h"

int		my_open_read(char *str, int flag)
{
  int		fd;
  int		ret;
  char		buffer[MEM_SIZE];

  clean_buffer(buffer);
  if ((fd = open(str, flag)) == -1)
    {
      my_putstr("open error\n");
      return (-1);
    }
  if ((ret = read(fd, buffer, MEM_SIZE)) == -1)
    {
      my_putstr("read error\n");
      return (-1);
    }
  close(fd);
  return (ret);
}

int		determ_champ_pos(char **argv, int *total)
{
 int		ret;
 int		i;

 i = 0;
 while (argv[i] != NULL)
   {
      if ((ret = my_open_read(argv[i++], O_RDONLY)) == -1)
	return (-1);
      if ((*total += ret) >= MEM_SIZE)
      	{
      	  my_putstr("Arena is full, champions cannot fight (total =");
	  my_putnbr(*total);
	  my_putstr(")\n");
      	  return (-1);
      	}
    }
 return (0);
}

int		fill_arena(char *file, char *arena, int *pos, t_champion *champ)
{
  int		fd;
  char		buffer[MEM_SIZE];
  int		i;
  int		ret;

  i = 0;
  clean_buffer(buffer);
  if ((fd = open(file, O_RDONLY)) == -1)
    return (-1);
  if ((ret = read(fd, buffer, MEM_SIZE)) == -1)
    return (-1);
  store_in_list(&champ, *pos);
  while (ret != 0)
    {
      arena[(*pos)++] = buffer[i++];
      ret = ret - 1;
    }
  arena[*pos] = 0;
  close(fd);
  return (0);
}

int		set_champ_in_mem(char **argv, int space,
				 char *arena, t_champion *champ)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (argv[i] != NULL)
    {
      if (fill_arena(argv[i], arena, &j, champ) == -1)
	return (-1);
      j += space;
      ++i;
    }
  return (0);
}
