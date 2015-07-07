/*
** my_strncmp.c for my_strncmp in /home/vadee_s/rendu/Piscine-C-Jour_06/ex_06
** 
** Made by vadee_s
** Login   <vadee_s@epitech.net>
** 
** Started on  Tue Oct  8 16:23:50 2013 vadee_s
** Last update Fri Mar 28 19:02:55 2014 vadee
*/

int		my_strncmp(char *s1, char *s2, int n)
{
  int		i;

  i = 0;
  while (i < n)
    {
      if (s1[i] == 0 || s2[i] == 0 || s1[i] != s2[i])
	return (-1);
      i = i + 1;
    }
  return (0);
}
