/*
** my_put_in_list.c for corewar in /home/menigo_m/rendu/Corewar/corewar
** 
** Made by a
** Login   <menigo_m@epitech.net>
** 
** Started on  Thu Apr 10 10:34:25 2014 a
** Last update Thu Apr 10 10:51:53 2014 a
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"

int		my_put_in_label(t_label **label, char *name, int loc)
{
  t_label	*element;

  element = malloc(sizeof(*element));
  if (element == NULL)
    exit_error("Malloc of put_in_label failed\n", "", 0);
  element->name = name;
  element->loc = loc;
  element->next = *label;
  *label = element;
  return (0);
}

t_instru	*list_init_instru(void)
{
  t_instru	*instru;

  instru = malloc(sizeof(*instru));
  if (instru == NULL)
    {
      my_putstr("Malloc of list initialisation failed\n");
      return (NULL);
    }
  instru->prev = instru;
  instru->next = instru;
  return (instru);
}

void	my_cp_tab(int tab1[MAX_ARGS_NUMBER],
		  int tab2[MAX_ARGS_NUMBER], char size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      tab1[i] = tab2[i];
      i = i + 1;
    }
}

void	my_cp_tab_char(char tab1[MAX_ARGS_NUMBER],
		       char tab2[MAX_ARGS_NUMBER], char size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      tab1[i] = tab2[i];
      i = i + 1;
    }
}

int		my_put_in_list(t_instru **instru, t_elem datas)
{
  t_instru	*element;

  element = malloc(sizeof(*element));
  if (element == NULL)
    exit_error("Malloc of put_in_list failed\n", "", 0);
  element->code = datas.fct;
  my_cp_tab(element->value, datas.params, get_nbr_args(datas.fct));
  my_cp_tab_char(element->type, datas.type, get_nbr_args(datas.fct));
  element->params = datas.code;
  element->prev = *instru;
  element->next = (*instru)->next;
  (*instru)->next->prev = element;
  (*instru)->next = element;
  return (0);
}
