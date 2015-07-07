/*
** corewar.h for corewar in /home/vadee_s/rendu/CPE_2014_corewar/corewar
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Thu Mar 27 14:45:54 2014 vadee
** Last update Sun Apr 13 22:25:29 2014 vadee_s
*/

#ifndef COREWAR_H_
# define COREWAR_H_
# define REGISTRE	1
# define DIRECT		2
# define INDIRECT	3

typedef struct		s_champion
{
  int			r[16];
  char			carry;
  char			*name;
  int			pc;
  char			son;
  int			rank;
  int			live;
  int			cycle_max;
  struct s_champion	*next;
  struct s_champion	*prev;
}			t_champion;

typedef struct		s_param
{
  int			type;
  int			param[3][2];
}			t_param;

typedef struct		s_functions
{
  char			opcode;
  int			(*ptrf)(t_param *param, t_champion *champ, char *arena);
  int			cycle;
  int			bitcode;
}			t_func;


/*
**main.c
*/
void			my_show_mem(char *str, int size);
void			display_error_magic(int player);
int			check_exec_magic(char *arena, t_champion *champ);

/*
**set_champ_in_mem.c
*/
int			my_open_read(char *str, int flag);
int			determ_champ_pos(char **argv, int *total);
int			fill_arena(char *file, char *arena, int *pos, t_champion *champ);
int			set_champ_in_mem(char **argv, int space,
					 char *arena, t_champion *champ);

/*
**asm_funcs_1.c
*/
int			live(t_param *param, t_champion *champ, char *arena);
int			ld(t_param *param, t_champion *champ, char *arena);
int			st(t_param *param, t_champion *champ, char *arena);
int			add(t_param *param, t_champion *champ, char *arena);
int			sub(t_param *param, t_champion *champ, char *arena);

/*
**asm_funcs_2.c
*/
int			calc_op(t_param *param, t_champion *champ, int op, char *arena);
int			and(t_param *param, t_champion *champ, char *arena);
int			or(t_param *param, t_champion *champ, char *arena);
int			xor(t_param *param, t_champion *champ, char *arena);
int			zjump(t_param *param, t_champion *champ, char *arena);

/*
**asm_funcs_3.c
*/
int			get_ldi_param(t_param *param, t_champion *champ, int *v1, int *v2);
int			ldi(t_param *param, t_champion *champ, char *arena);
int			get_sti_param(t_param *param, t_champion *champ, int *v1, int *v2);
int			sti(t_param *param, t_champion *champ, char *arena);
int			my_fork(t_param *param, t_champion *champ, char *arena);

/*
**asm_funcs_4.c
*/
int			lld(t_param *param, t_champion *champ, char *arena);
int			lldi(t_param *param, t_champion *champ, char *arena);
int			my_lfork(t_param *param, t_champion *champ, char *arena);
int			aff(t_param *param, t_champion *champ, char *arena);

/*
**get_param1.c
*/
void			get_param_5(t_param *param, char bitcode, int *j, int l);
void			get_param(t_param *param, t_champion **champ, char *arena, int i);

/*
**get_param2.c
*/
int			get_param_4(t_param *param, t_champion **champ, char *arena, int l);
int			get_param_3(t_param *param, t_champion **champ, char *arena, int i);
int			get_param_2(t_param *param, t_champion **champ, char *arena, int i);
int			get_param_1(t_param *param, t_champion *champ, char *arena, int i);

/*
**my_lists.c
*/
int			store_in_list(t_champion **champ, int pos);
int			init_list(t_champion **champ);
void			suppr_elem_select(t_champion *elem);

/*
**trunc.c
*/
int			process_test_opcode(char *arena, t_champion **tmp, int i);
int			loop_champ(char *arena, t_champion *champ, int *nb_champ);
int			loop_cycle_to_die(char *arena, t_champion *champ,
					  int *nb_champ, int lower);
int			loop_nb_champ(char *arena, t_champion *champ,
				      int *nb_champ, long nbr_cycle);

/*
**is_alive.c
*/
void			ranking(t_champion *champ);
int			check_live(t_champion *champ, int *nb_champ);
int			check_alive(t_champion *champ, int nb_champ,
				    int *nbr_alive, int *lower);

/*
**basics_funcs.c
*/
char			*my_strdup(char *src);
void			clean_buffer(char *buffer);
void			my_putstr(char *str);
void			my_putchar(char c);
int			my_strlen(char *str);
char			*my_strdup_uns(unsigned char *src);

/*
**my_getnbr.c
*/
int			my_getnbr(char *str);

/*
**my_getnbr.c
*/
int			my_putnbr(int nb);

/*
**my_strcmp.c
*/
int			my_strcmp(char *s1, char *s2);

/*
**my_strncmp.c
*/
int			my_strncmp(char *s1, char *s2, int n);

static const t_func	g_func[17] =
{
  {0x01, &live, 10, 0x40},
  {0x02, &ld, 5, -1},
  {0x03, &st, 5, -1},
  {0x04, &add, 10, -1},
  {0x05, &sub, 10, -1},
  {0x06, &and, 6, -1},
  {0x07, &or, 6, -1},
  {0x08, &xor, 6, -1},
  {0x09, &zjump, 20, 0xc0},
  {0x10, &aff, 2, -1},
  {0x0a, &ldi, 25, -1},
  {0x0b, &sti, 25, -1},
  {0x0c, &my_fork, 800, 0xc0},
  {0x0d, &lld, 10, -1},
  {0x0e, &lldi, 50, -1},
  {0x0f, &my_lfork, 1000, 0xc0},
  {0, NULL, -1, 0}
};

#endif /* !COREWAR_H_*/
