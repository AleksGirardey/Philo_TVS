/*
** Fct_usuelles.c for Philosophes in /home/girard_x/GITREP/Philo_TVS
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Sat Feb 28 14:32:56 2015 ALEXIS GIRARDEY
** Last update Sun Mar  1 19:26:18 2015 ALEXIS GIRARDEY
*/

#include <unistd.h>
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

int		can_eat(t_philo	*philo)
{
  if (philo->bol->baguette == LIBRE && philo->next->bol->baguette == LIBRE)
    return (1);
  else
    return (0);
}

struct s_philo		*need_that_philo(t_philo *table, int id)
{
  t_philo		*tmp;

  tmp = table;
  while (tmp->id != id)
    tmp = tmp->next;
  return (tmp);
}
