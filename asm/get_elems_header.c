/*
** get_elems_header.c for corewar in /home/menigo_m/rendu/Corewar/corewar
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Thu Apr 10 10:25:46 2014 a
** Last update Thu Apr 10 10:26:02 2014 a
*/

#include <stdlib.h>

char	*get_name(char *line)
{
  int	i;
  int	size;
  char	*name;

  i = 0;
  while (line[i] != '"' && line[i] != '\0')
    i = i + 1;
  if (line[i] == '\0')
    return (NULL);
  i = i + 1;
  size = 0;
  while (line[i + size] != '"' && line[i + size] != '\0')
    size = size + 1;
  if (line[i + size] == '\0')
    return (NULL);
  if ((name = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  size = 0;
  while (line[i + size] != '"' && line[i + size] != '\0')
    {
      name[size] = line[i + size];
      size = size + 1;
    }
  name[size] = '\0';
  return (name);
}

char	*get_comment(char *line)
{
  int	i;
  int	size;
  char	*comment;

  i = 0;
  while (line[i] != '"' && line[i] != '\0')
    i = i + 1;
  if (line[i] == '\0')
    return (NULL);
  i = i + 1;
  size = 0;
  while (line[i + size] != '"' && line[i + size] != '\0')
    size = size + 1;
  if (line[i + size] == '\0')
    return (NULL);
  if ((comment = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  size = 0;
  while (line[i + size] != '"' && line[i + size] != '\0')
    {
      comment[size] = line[i + size];
      size = size + 1;
    }
  comment[size] = '\0';
  return (comment);
}
