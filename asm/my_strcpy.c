/*
** my_strcpy.c for my_strcpy in /home/lopes_n/rendu/PSU_2013_minishell1
** 
** Made by lopes_n
** Login   <lopes_n@epitech.net>
** 
** Started on  Mon Dec 30 10:41:10 2013 lopes_n
** Last update Mon Dec 30 10:41:27 2013 lopes_n
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
