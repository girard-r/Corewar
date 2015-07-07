/*
** parsing.c for parsing in /home/girard_r/Documents/Corewar/Parsing
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Fri Apr 11 20:36:01 2014 girard_r
** Last update Sun Apr 13 17:11:09 2014 girard_r
*/

#include <stdlib.h>
#include "parsing.h"

int		load_address_validity(int *i, int *count, char **av)
{
  if (my_strcmp(av[*i], "-a") == 0)
    {
      *i += 1;
      if (av[*i] == NULL)
	return (1);
      if (my_isnumber(av[*i]) != 0)
	return (5);
      *i += 1;
    }
  return (prog_name_validity(i, count, av));
}

int		prog_number_validity(int *i, int *count, char **av)
{
  if (my_strcmp(av[*i], "-n") == 0)
    {
      *i += 1;
      if (av[*i] == NULL)
	return (1);
      if (my_isnumber(av[*i]) != 0)
	return (4);
      *i += 1;
      if (av[*i] == NULL)
	return (1);
    }
  return (load_address_validity(i, count, av));
}

int		champ_validity(int *i, int *count, char **av)
{
  int		error;

  if (my_isnumber_hex(av[*i]) == 0)
    {
      *i += 1;
      if (av[*i] != NULL)
	{
	  while (av[*i])
	    {
	      if ((error = prog_number_validity(i, count, av)) != 0)
		return (error);
	    }
	}
      else
	return (6);
    }
  else
    return (3);
  return (0);
}

int		dump_validity(int ac, char **av)
{
  int		i;
  int		error;
  int		count;

  count = 0;
  error = 0;
  if (ac > 1)
    {
      i = 1;
      if (my_strcmp(av[i++], "-dump") == 0 && av[i] != NULL)
	error = champ_validity(&i, &count, av);
      else
	error = 2;
    }
  else
    error = 1;
  if (error != 0)
    {
      get_error(error);
      return (-1);
    }
  return (count);
}

int		parsing(int ac, char **av, t_info *parse)
{
  int		nb_champ;

  if ((nb_champ = dump_validity(ac, av)) == -1)
    return (-1);
  if (nb_champ > 4)
    {
      my_putstr("Too many champions: LIMIT: 4\n");
      return (-1);
    }
  if ((parse->prog_name = malloc(sizeof(char *) * (nb_champ + 1))) == NULL)
    return (-1);
  fill_tab(av, parse->prog_name);
  parse->nbr_cycle = my_getnbr_base_long(av[2], "0123456789ABCDEF");
  parse->nb_champ = nb_champ;
  return (0);
}
