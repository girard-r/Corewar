/*
** suppr_elelem_list.c for suppr_elem_list in /home/vadee_s/rendu/CPE_2013_Pushswap/src
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Sat Dec 21 19:42:44 2013 vadee
** Last update Fri Apr 11 23:13:28 2014 vadee
*/
#include <stdlib.h>
#include "corewar.h"

void		suppr_elem_select(t_champion *elem)
{
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
}
