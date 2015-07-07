/*
** asm.h for asm in /home/lopes_n/rendu/corewar/header
** 
** Made by lopes_n
** Login   <lopes_n@epitech.net>
** 
** Started on  Tue Mar 18 16:58:12 2014 lopes_n
** Last update Fri Apr 11 10:55:29 2014 a
*/

#ifndef ASM_H_
# define ASM_H_

#define INVERT_ENDIAN(nb) (LOW_BIT(nb) | HIGH_BIT(nb))
#define LOW_BIT(nb) (((nb >> 24) & 0xff) | ((nb << 8) & 0xff0000))
#define HIGH_BIT(nb) (((nb >> 8) & 0xff00) | ((nb << 24) & 0xff000000))
#define INVERT_ENDIAN_SHORT(nb) (((nb >> 8) & 0x00ff) | ((nb << 8) & 0xff00))

typedef struct		s_instru
{
  char			code;
  char			params;
  int			value[MAX_ARGS_NUMBER];
  char			type[MAX_ARGS_NUMBER];
  struct s_instru	*prev;
  struct s_instru	*next;
}			t_instru;

typedef struct		s_label
{
  char			*name;
  int			loc;
  struct s_label	*next;
  struct s_label	*prev;
}			t_label;

typedef struct		s_elem
{
  char			fct;
  char			code;
  int			params[MAX_ARGS_NUMBER];
  char			type[MAX_ARGS_NUMBER];
  int			line_nbr;
}			t_elem;

int		is_ind(char code);
int		is_empty(char *line);
char		*get_lab_char(int size);
int		verif_endian(void);
void		exit_error(char *str, char *name, int line);
char		*check_wr_name(char *name);

/*
** LIB FCTS
*/

char		*my_strcpy(char *dest, char *src);
char		*my_strcat(char *dest, char *src);
int		my_strcmp(char *s1, char *s2);
void		my_putchar(char c);
int		my_put_nbr(int nb);
int		start_cmp(char *str1, char *str2);
int		end_cmp(char *str1, char *str2);
int		my_strlen(char *str);
void		my_putstr(char *str);
char		*epur_str(char *str);
int		is_in_str(char *str);
int		is_nbr(char *str);
char		**my_str_to_wordtab(char *str);

/*
** PRINT FCTS
*/

void		print_ins(t_instru *instruction, int fd);
void		print_values(t_instru *instruction, int fd);
void		print_in_file(char *name, header_t *header,
			      t_instru *instruction, int size);

/*
** LABELS FCTS
*/

t_label		*get_label(int fd, t_label *label, int *line_nbr);
int		my_put_in_label(t_label **label, char *name, int loc);
int		get_loc(char *name, t_label *label);
char		get_fct_label(char *name, int line_nbr, char *line);
void		get_args_label(char **tab, char type[MAX_ARGS_NUMBER],
		       int line_nbr, char *line);
void		get_params_label(char **tab, int params[MAX_ARGS_NUMBER]);
int		get_size_label(char code, char type[MAX_ARGS_NUMBER]);

/*
** INSTRUCTIONS FCTS
*/

t_instru	*put_instruction(int fd, t_instru *instruction,
				 int *size, t_label *label);
int		my_put_in_list(t_instru **instru, t_elem datas);
char		get_nbr_args(char code);
int		get_size(t_instru *instruction);
char		type_args(char *arg, char type[MAX_ARGS_NUMBER], int i);
int		my_getnbr_param(char *str);
char		get_fct(char *name);
char		get_code(char **tab, char fct,
			 char type[MAX_ARGS_NUMBER], char *line);
void		get_params(char **tab, int params[MAX_ARGS_NUMBER],
			   t_label *label, int size);
t_instru	*list_init_instru(void);

/*
** HEADER FCTS
*/

int		put_header(int fd, header_t *header, int *line_nbr);
int		is_comment(char *str);
char		*get_name(char *line);
char		*get_comment(char *line);
void		init_header(header_t *header);

#endif /* !ASM_H_ */
