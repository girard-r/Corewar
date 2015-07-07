/*
** my_getnbr.c for my_getnbr in /home/vadee_s/rendu/Piscine-C-lib/my
** 
** Made by vadee_s
** Login   <vadee_s@epitech.net>
** 
** Started on  Tue Oct  8 13:13:07 2013 vadee_s
** Last update Sun Apr 13 20:45:09 2014 girard_r
*/

int	my_getnbr(char *str)
{
  int	nb_sign;
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  nb_sign = 1;
  if (str[0] == 45)
    nb_sign = - 1;
  while (str[i] >= 48 && str[i] <= 57)
    {
      nb = nb * 10 + str[i] - 48;
      i = i + 1;
    }
  return (nb * nb_sign);
}
