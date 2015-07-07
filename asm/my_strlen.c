/*
** my_strlen.c for my_strlen.c in /home/lopes_n/rendu/Piscine-C-Jour_03
** 
** Made by lopes_n
** Login   <lopes_n@epitech.net>
** 
** Started on  Thu Oct  3 08:34:17 2013 lopes_n
** Last update Thu Dec  5 11:12:10 2013 lopes_n
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
