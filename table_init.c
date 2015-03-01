/*
** table_init.c for Philosophes in /home/girard_x/GITREP/Philo_TVS
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Thu Feb 26 10:12:41 2015 ALEXIS GIRARDEY
<<<<<<< HEAD
** Last update Sun Mar  1 20:55:36 2015 ALEXIS GIRARDEY
=======
** Last update Sun Mar  1 20:30:18 2015 Mathieu Chassara
>>>>>>> 45371d8aad915e04d95b6b88f6cd39df67afecc1
*/

#include <stdio.h>
#include <stdlib.h>
#include "Fct_usuelles.h"
#include "Philosophes.h"
#include "Bol.h"
#include "actions.h"

struct s_bol	*init_bol()
{
  t_bol		*newBol;

  if ((newBol = (t_bol *) malloc(sizeof(struct s_bol)) == NULL))
    exit(0);
  newBol->bol = PLEIN;
  newBol->baguette = LIBRE;
  return (newBol);
}

struct s_philo	*init_philo(t_bol *bol, int id)
{
  t_philo	*newPhilo;

  if ((newPhilo = (t_philo *) malloc(sizeof(struct s_philo)) == NULL))
    exit(0);
  newPhilo->id = id;
  newPhilo->etat = REPOS;
  newPhilo->bol = bol;
  newPhilo->next = NULL;
}

struct s_philo	*init_table()
{
  int		i;
  t_philo	*table;
  t_philo	*temp;

  i = 1;
  table = init_philo(init_bol(), i);
  temp = table;
  i++;
  while (i < 8)
    {
      temp->next = init_philo(init_bol(), i);
      temp = temp->next;
      ++i;
    }
  temp->next = table;
  return (table);
}

struct s_philo	*lets_eat(t_philo *table)
{
  int		i;
  t_philo	*philo;

  i = 1;
  while (i < 8)
    {
      table->need_ID = i;
      philo = need_that_philo(table, i);
      pthread_create(&(philo->thread), NULL, philo_meca, philo);
      ++i;
    }
  return (table);
}
