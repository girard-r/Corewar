/*
** header.c for header.c in /home/lopes_n/rendu/corewar
** 
** Made by lopes_n
** Login   <lopes_n@epitech.net>
** 
** Started on  Mon Mar 17 17:58:41 2014 lopes_n
** Last update Sun Apr 13 21:59:19 2014 vadee
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"
#include "get_next_line.h"

void	init_header(header_t *header)
{
  int	i;
  char	*tmp;
  int	size;

  size = sizeof(*header);
  tmp = (char *)header;
  i = 0;
  while (i < size)
    {
      tmp[i] = 0;
      i = i + 1;
    }
}

void	clear_buf(char *buf, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      buf[i] = 0;
      i = i + 1;
    }
}

void	fill_header(char *name, char *comment, header_t *header)
{
  if (my_strlen(name) > PROG_NAME_LENGTH)
    {
      my_putstr("Error : The Name is too long\n");
      exit(EXIT_FAILURE);
    }
  if (my_strlen(comment) > COMMENT_LENGTH)
    {
      my_putstr("Error : The comment is too long\n");
      exit(EXIT_FAILURE);
    }
  if (verif_endian() == 1)
    header->magic = INVERT_ENDIAN(COREWAR_EXEC_MAGIC);
  clear_buf(header->prog_name, PROG_NAME_LENGTH + 1);
  my_strcpy(header->prog_name, name);
  header->prog_size = 0;
  clear_buf(header->comment, COMMENT_LENGTH + 1);
  my_strcpy(header->comment, comment);
}

char	*check_header(int fd, header_t *header, int *line_nbr)
{
  char	*line;
  char	*name;
  char	*comment;

  name = NULL;
  comment = NULL;
  while ((line = get_next_line(fd)) != NULL)
    {
      if (start_cmp(NAME_CMD_STRING, line) == 0 && !(name = get_name(line)))
	return (line);
      else if (start_cmp(COMMENT_CMD_STRING, line) == 0 &&
	       !(comment = get_comment(line)))
	return (line);
      else if (is_comment(line) != 0 && is_empty(line) != 0 &&
	       start_cmp(NAME_CMD_STRING, line) != 0 &&
	       start_cmp(COMMENT_CMD_STRING, line) != 0)
	return (line);
      if (name != NULL && comment != NULL)
	{
	  fill_header(name, comment, header);
	  return (NULL);
	}
      *line_nbr = *line_nbr + 1;
    }
  return ("Header incomplet");
}

int	put_header(int fd, header_t *header, int *line_nbr)
{
  char	*error;

  error = check_header(fd, header, line_nbr);
  if (*line_nbr > 500)
    exit_error("Too much lines in the champ", "", 0);
  if (error != NULL)
    {
      my_putstr("Error at line : ");
      my_putstr(error);
      my_putchar(10);
      return (-1);
    }
  return (0);
}
