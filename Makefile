##
## Makefile for corewar in /home/vadee_s/rendu/CPE_2014_corewar
## 
## Made by vadee_s
## Login   <vadee_s@epitech.net>
## 
## Started on  Sun Apr 13 22:16:10 2014 vadee_s
## Last update Sun Apr 13 22:16:12 2014 vadee_s
##

CC		=	cc

RM		=	rm -f

NAMEASM		=	asm

NAMEVM		=	corewar

DIRVM		=	corewar

DIRASM		=	asm

SRCASM		=	$(DIRASM)/main.c \
			$(DIRASM)/get_next_line.c \
			$(DIRASM)/exit_error.c \
			$(DIRASM)/get_size.c \
			$(DIRASM)/epur_str.c \
			$(DIRASM)/print_params.c \
			$(DIRASM)/is_in_str.c \
			$(DIRASM)/check_wr_name.c \
			$(DIRASM)/my_asm_list.c \
			$(DIRASM)/get_params.c \
			$(DIRASM)/get_elems_header.c \
			$(DIRASM)/get_elems_label.c \
			$(DIRASM)/is_nbr.c \
			$(DIRASM)/get_code_fct.c \
			$(DIRASM)/header.c \
			$(DIRASM)/instructions.c \
			$(DIRASM)/my_putchar.c \
			$(DIRASM)/my_putstr.c \
			$(DIRASM)/my_strcat.c \
			$(DIRASM)/my_strcpy.c \
			$(DIRASM)/my_str_to_wordtab.c \
			$(DIRASM)/my_getnbr_param.c \
			$(DIRASM)/my_strcmp_fcts.c \
			$(DIRASM)/print_ins.c \
			$(DIRASM)/op.c \
			$(DIRASM)/check_header.c \
			$(DIRASM)/my_put_nbr.c \
			$(DIRASM)/get_label.c \
			$(DIRASM)/my_strlen.c \

SRCVM		=	$(DIRVM)/main.c \
			$(DIRVM)/basic_funcs.c \
			$(DIRVM)/set_champ_in_mem.c \
			$(DIRVM)/my_lists.c \
			$(DIRVM)/my_strncmp.c \
			$(DIRVM)/my_getnbr.c \
			$(DIRVM)/asm_funcs_1.c \
			$(DIRVM)/asm_funcs_2.c \
			$(DIRVM)/asm_funcs_3.c \
			$(DIRVM)/asm_funcs_4.c \
			$(DIRVM)/trunc.c \
			$(DIRVM)/is_alive.c \
			$(DIRVM)/my_strcmp.c \
			$(DIRVM)/suppr_elem_list.c \
			$(DIRVM)/Parsing/basics.c \
			$(DIRVM)/Parsing/parsing.c \
			$(DIRVM)/Parsing/validity.c \
			$(DIRVM)/my_putnbr.c \
			$(DIRVM)/get_param1.c \
			$(DIRVM)/get_param2.c \
			$(DIRVM)/my_strdup_uns.c


OBJASM		=	$(SRCASM:.c=.o)

OBJVM		=	$(SRCVM:.c=.o)

all		:	$(NAMEVM) $(NAMEASM)

$(NAMEVM)	:	$(OBJVM)
			$(CC) -o $(DIRVM)/$(NAMEVM) $(OBJVM)

$(NAMEASM)	:	$(OBJASM)
			$(CC) -o $(DIRASM)/$(NAMEASM) $(OBJASM)

clean		:
			$(RM) $(OBJVM) $(OBJASM)

fclean		:	clean
			$(RM) $(DIRVM)/$(NAMEVM) $(DIRASM)/$(NAMEASM)

re		:	fclean all

.PHONY		:	all clean fclean re
