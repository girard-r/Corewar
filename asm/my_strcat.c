/*
** my_strcat.c for my_strcat.c in /home/lopes_n/rendu/Piscine-C-Jour_07/ex_01
** 
** Made by lopes_n
** Login   <lopes_n@epitech.net>
** 
** Started on  Tue Oct  8 17:40:54 2013 lopes_n
** Last update Wed Oct  9 16:27:35 2013 lopes_n
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	y;

  i = 0;
  y = 0;
  while (dest[i] != '\0')
    {
      i = i + 1;
    }
  while (src[y] != '\0')
    {
      dest[i] = src[y];
      i = i + 1;
      y = y + 1;
    }
  dest[i] = '\0';
  return (dest);
}
