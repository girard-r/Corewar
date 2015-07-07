/*
** my_put_nbr.c for my_put_nbr.c in /home/menigo_m/rendu/Piscine-C-Jour_03
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Wed Oct  2 16:46:14 2013 a
** Last update Thu Apr 10 10:51:53 2014 a
*/

#include "op.h"
#include "asm.h"

int	my_put_nbr(int nb)
{
  int	div;

  div = 1;
  if (nb == -2147483648)
    {
      my_putchar('-');
      my_putchar('2');
      nb = 147483648;
    }
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  while (div <= (nb / 10))
    div = div * 10;
  while (div >= 1)
    {
      my_putchar(nb / div + '0');
      nb = nb % div;
      div = div / 10;
    }
  return (0);
}
