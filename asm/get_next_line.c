/*
** get_next_line.c for get_next_line in /home/lopes_n/rendu/CPE_2013_getnextline
** 
** Made by lopes_n
** Login   <lopes_n@epitech.net>
** 
** Started on  Fri Nov 22 10:13:52 2013 lopes_n
** Last update Thu Apr 10 10:51:54 2014 a
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "op.h"
#include "asm.h"

char	*my_re_alloc(char *str, int size)
{
  char	*tmp;

  str[size - NB_CHAR(BUFF_SIZE) - 2] = '\0';
  tmp = malloc(sizeof(char) * size);
  if (tmp == NULL)
    return (NULL);
  my_strcpy(tmp, str);
  free(str);
  return (tmp);
}

void	get_next_line_complete(char *output, char *buffer, int *z, int *y)
{
  output[*z] = '\0';
  if (buffer[*y] == '\n')
    *y = *y + 1;
}

char	*get_cond(const int fd, t_count *count, char *buffer, char **output)
{
  int	z;

  if (count->y == count->i)
    {
      z = 0;
      while (z < NB_CHAR(BUFF_SIZE))
	{
	  buffer[z] = 0;
	  z = z + 1;
	}
      count->i = read(fd, buffer, NB_CHAR(BUFF_SIZE));
      if (count->i == -1)
	return (NULL);
      count->y = 0;
      if ((*output = my_re_alloc(*output,
				 NB_CHAR(BUFF_SIZE) + count->z + 2)) == NULL)
	return (NULL);
    }
  return (buffer);
}

char			*get_next_line(const int fd)
{
  static char		buffer[NB_CHAR(BUFF_SIZE)];
  static t_count	count;
  char			*output;

  count.z = 0;
  if (count.i == 0)
    count.i = read(fd, buffer, NB_CHAR(BUFF_SIZE));
  output = malloc(sizeof(char) * (NB_CHAR(BUFF_SIZE) + 1));
  if (output == NULL || count.i == -1)
    return (NULL);
  while (buffer[count.y] != '\n' && count.i > 0)
    {
      if (get_cond(fd, &count, buffer, &output) == NULL)
	return (NULL);
      if (count.y < count.i)
	output[count.z++] = buffer[count.y++];
      if (count.z == 0)
	return (NULL);
    }
  get_next_line_complete(output, buffer, &count.z, &count.y);
  if (count.i == 0 && count.z < 1)
    return (NULL);
  return (output);
}
