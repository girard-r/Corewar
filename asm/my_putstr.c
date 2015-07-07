/*
** my_putstr.c for my_putstr in /home/lopes_n/rendu/corewar/header
** 
** Made by lopes_n
** Login   <lopes_n@epitech.net>
** 
** Started on  Mon Mar 17 18:20:12 2014 lopes_n
** Last update Thu Apr 10 10:51:53 2014 a
*/

#include "op.h"
#include "asm.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
