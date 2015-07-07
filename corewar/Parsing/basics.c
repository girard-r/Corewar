/*
** my_getnbr_base.c for my_getnbr_base.c in /home/girard_r/Documents/102chiffrement
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Tue Nov 19 19:04:31 2013 girard_r
** Last update Sun Apr 13 16:57:06 2014 girard_r
*/

#include "parsing.h"

long		my_power_rec(long nb, int power)
{
  long		a;

  if (power < 0)
    return ((long)0);
  if (power == 0)
    return ((long)1);
  a = nb * my_power_rec(nb, power - 1);
  return (a);
}

long		check_pos(char c, char *base)
{
  long		i;

  i = 0;
  while (base[i] != 0)
    {
      if (c == base[i])
	return (i);
      i = i + 1;
    }
  return (-1);
}

long int	my_getnbr_base_long(char *str, char *base)
{
  long int	len_base;
  int		i;
  long int	result;

  i = 0;
  result = 0;
  len_base = my_strlen(base);
  while (str[i] != 0)
    {
      result = result + check_pos(str[i], base)
	* my_power_rec(len_base, my_strlen(str) - i - 1);
      i = i + 1;
    }
  return (result);
}
