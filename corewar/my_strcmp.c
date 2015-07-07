/*
** my_strcmp.c for my_strcmp in /home/girard_r/Documents/Piscine-C-Jour_06
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Mon Oct  7 09:45:17 2013 girard_r
** Last update Sat Apr 12 00:06:59 2014 girard_r
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s1[i] == s2[i])
    {
      if (s1[i] == '\0')
	return (0);
      i = i + 1;
    }
  return (s1[i] - s2[i]);
}
