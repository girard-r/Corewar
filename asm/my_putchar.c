/*
** my_putchar.c for my_putchar in /home/lopes_n/rendu/corewar/header
** 
** Made by lopes_n
** Login   <lopes_n@epitech.net>
** 
** Started on  Mon Mar 17 18:19:45 2014 lopes_n
** Last update Tue Apr  1 12:09:19 2014 a
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
