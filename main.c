/*
** main.c for Philosophes in /home/girard_x/GITREP/Philo_TVS
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Sun Mar  1 16:21:03 2015 ALEXIS GIRARDEY
** Last update Sun Mar  1 16:28:48 2015 ALEXIS GIRARDEY
*/

#include "Philosophes.h"
#include "Bol.h"
#include "actions.h"
#include "Fct_usuelles.h"

void	philo_wait(t_philo *table)
{
  int	i;
  t_philo	*tmp;


  i = 0;
  tmp = table;
  while (i < 7)
    {
      pthread_join(tmp->thread, NULL);
      tmp = tmp->next;
      i++;
    }
}

int	main(void)
{
  t_philo	*table;

  table = init_table();
  srand(time(NULL));
  lets_eat(table);
  philo_wait(table);
  return (0);
}
