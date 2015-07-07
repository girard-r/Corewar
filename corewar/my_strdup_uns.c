/*
** my_strdup_uns.c for my_strdup_uns in /home/girard_r/Documents/Corewar/vm
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sun Apr 13 21:24:02 2014 girard_r
** Last update Sun Apr 13 21:37:30 2014 vadee
*/

#include <stdlib.h>
#include "corewar.h"

char	*my_strdup_uns(unsigned char src[129])
{
  int		i;
  char		*dest;

  i = 0;
  dest = malloc(my_strlen(src) + 1);
  if (dest == NULL)
    return (NULL);
  while (src[i] != 0)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
