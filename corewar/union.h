/*
** union.h for union.h in /home/girard_r/Documents/Corewar
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Tue Apr  8 00:02:59 2014 girard_r
** Last update Wed Apr  9 15:34:32 2014 vadee
*/

#ifndef UNION_H_
# define UNION_H_

union			u_short
{
  short			nb;
  char			ch[2];
};

union			u_int
{
  int			nb;
  char			ch[4];
};

#endif /* !UNION_H_ */
