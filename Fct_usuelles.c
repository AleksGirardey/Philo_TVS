/*
** Fct_usuelles.c for Philosophes in /home/girard_x/GITREP/Philo_TVS
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Sat Feb 28 14:32:56 2015 ALEXIS GIRARDEY
** Last update Sat Feb 28 14:42:26 2015 ALEXIS GIRARDEY
*/

#include "Fct_usuelles.h"

int		nb_bols_plein(t_philo *table)
{
  int		count;
  t_philo	*tmp;

  count = 0;
  tmp = table;
  while (tmp != NULL)
    {
      if (tmp->bol->bol == 2)
	count ++;
      tmp = tmp->next;
    }
  return (count);
}
