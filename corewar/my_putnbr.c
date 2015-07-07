/*
** my_put_nbr.c for my_put_nbr in /home/girard_r/Documents/Piscine-C-Jour_03
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Thu Oct  3 10:19:57 2013 girard_r
** Last update Sun Apr 13 19:30:56 2014 girard_r
*/

int	my_putnbr(int nb)
{
  int	a;
  int	nb2;

  a = 1;
  while (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  nb2 = nb;
  while (nb2 >= 10)
    {
      nb2 = nb2 / 10;
      a = a * 10;
    }
  while (a > 0)
    {
      my_putchar((nb / a) % 10 + '0');
      a = a / 10;
    }
  return (nb);
}
