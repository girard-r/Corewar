/*
** parsing.h for parsing in /home/girard_r/Documents/Corewar/Parsing
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Fri Apr 11 20:34:03 2014 girard_r
** Last update Sun Apr 13 17:11:29 2014 girard_r
*/

#ifndef PARSING_H_
# define PARSING_H_

typedef	struct	s_info
{
  long		nbr_cycle;
  int		nb_champ;
  char		**prog_name;
}		t_info;

long		check_pos(char c, char *base);
long		my_power_rec(long nb, int power);
long		my_getnbr_base_long(char *str, char *base);
int		my_isnumber_hex(char *str);
int		my_isnumber(char *str);
void		get_error(int error);
int		prog_name_validity(int *i, int *count, char **av);
int		load_address_validity(int *i, int *count, char **av);
int		prog_number_validity(int *i, int *count, char **av);
int		champ_validity(int *i, int *count, char **av);
int		dump_validity(int ac,char **av);
void		fill_tab(char **av, char **tab_champ);
int		parsing(int ac, char **av, t_info *parse);

#endif /* !PARSING_H_ */
