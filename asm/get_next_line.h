/*
** get_next_line.h for get_next_line in /home/lopes_n/rendu/CPE_2013_getnextline
** 
** Made by lopes_n
** Login   <lopes_n@epitech.net>
** 
** Started on  Fri Nov 22 10:14:52 2013 lopes_n
** Last update Mon Dec  2 09:56:09 2013 lopes_n
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# define BUFF_SIZE (1024)
# define NB_CHAR(i) ((i > 0) ? i : 0)

char	*get_next_line(const int fd);

typedef struct	s_count
{
  int		i;
  int		y;
  int		z;
}		t_count;

#endif /* !GET_NEXT_LINE_H_ */
