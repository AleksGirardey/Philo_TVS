/*
** main.c for Philosophes in /home/girard_x/GITREP/Philo_TVS
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Sun Mar  1 16:21:03 2015 ALEXIS GIRARDEY
** Last update Sun Mar  1 20:53:28 2015 ALEXIS GIRARDEY
*/

#include "Philosophes.h"
#include "Bol.h"
#include "actions.h"
#include "Fct_usuelles.h"

struct s_philo	*init_table();

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
      ++i;
    }
}

void	clean_table(t_philo *table)
{
  if (table->id != 7)
    clean_table(table->next);
  table->next = NULL;
  free(table->bol);
  free(table);
}

int	main(void)
{
  t_philo	*table;

  srand(time(NULL));

  table = init_table();
  table = lets_eat(table);
  philo_wait(table);
  clean_table(table);
  return (0);
}
