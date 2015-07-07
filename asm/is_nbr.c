/*
** is_nbr.c for corewar in /home/menigo_m/rendu/Corewar/corewar
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Thu Apr 10 10:29:37 2014 a
** Last update Thu Apr 10 10:59:54 2014 a
*/

int	is_nbr(char *str)
{
  int	i;

  i = 0;
  if (str[i] == '\\')
    i = i + 1;
  if (str[i] == 'r' || str[i] == '%')
    i = i + 1;
  while ((str[i] == '-' || str[i] == '+') && str[i] != '\0')
    i = i + 1;
  if (str[i] == '\0')
    return (-1);
  while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
    i = i + 1;
  if (str[i] != '\0')
    return (-1);
  else
    return (1);
}
