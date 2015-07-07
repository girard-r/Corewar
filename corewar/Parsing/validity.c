/*
** validity.c for validity in /home/girard_r/Documents/Parsing
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sun Apr 13 16:39:54 2014 girard_r
** Last update Sun Apr 13 16:49:40 2014 girard_r
*/

#include <stdlib.h>
#include "parsing.h"

static const char	g_error[7][100]=
  {
    {"not enough arguments\n"},
    {"First arguments must be [-dump nbr_cycle]\n"},
    {"[-dump]: (positive)number in xx-mode: AB0563F02...\n"},
    {"[-n]: prog_number must be a (positive)number\n"},
    {"[-a]: load_address must be a (positive)number\n"},
    {"Usage: ./corewar [-dump nbr_cycle] "},
    {"[[-n prog_number] [-a load_address ] prog_name] ...\n"}
  };

int		my_isnumber_hex(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || (str[i] > '9' && str[i] < 'A')
	  || str[i] > 'F')
	return (-1);
      i += 1;
    }
  return (0);
}

int		my_isnumber(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      i += 1;
    }
  return (0);
}

void		get_error(int error)
{
  int		i;

  i = 0;
  if (error != 6)
    my_putstr(g_error[error - 1]);
  my_putstr(g_error[5]);
  my_putstr(g_error[6]);
  return ;
}

void		fill_tab(char **av, char **tab_champ)
{
  int		i;
  int		j;

  i = 1;
  j = 0;
  while (av[i])
    {
      if (av[i][0] == '-')
	i += 2;
      else
	tab_champ[j++] = av[i++];
    }
  tab_champ[j] = NULL;
}

int		prog_name_validity(int *i, int *count, char **av)
{
  if (av[*i] == NULL)
    return (1);
  if (av[*i][0] != '-')
    {
      *i += 1;
      *count += 1;
      return (0);
    }
  else
    return (6);
}
