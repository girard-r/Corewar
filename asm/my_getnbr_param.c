/*
** my_getnbr.c for my_getnbr.c in /home/lopes_n/rendu/Piscine-C-Jour_04
** 
** Made by lopes_n
** Login   <lopes_n@epitech.net>
** 
** Started on  Mon Oct 21 14:47:18 2013 lopes_n
** Last update Tue Apr  8 17:14:39 2014 a
*/

#include <stdlib.h>

int	def_sign(char *str, int *i)
{
  int	sign;

  *i = 0;
  sign = 1;
  if (str[*i] == '\\')
    *i = *i + 1;
  if (str[*i] == 'r' || str[*i] == '%')
    *i = *i + 1;
  while (str[*i] == '+' || str[*i] == '-')
    {
      if (str[*i] == '-')
	sign = sign + 1;
      *i = *i + 1;
    }
  return (sign);
}

int	my_getnbr_param(char *str)
{
  int	i;
  int	sign;
  int	nbr;

  if (str == NULL)
    return (0);
  i = 0;
  sign = def_sign(str, &i);
  nbr = 0;
  while (str[i] > 47 && str[i] < 58)
    {
      nbr = nbr + str[i] - 48;
      if (str[i + 1] > 47 && str[i + 1] < 58)
	{
	  if (nbr >= 214748365)
	    return (0);
	  nbr = nbr * 10;
	}
      i = i + 1;
    }
  if (sign % 2 == 0)
    return (-nbr);
  return (nbr);
}
