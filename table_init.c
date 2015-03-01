/*
** table_init.c for Philosophes in /home/girard_x/GITREP/Philo_TVS
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Thu Feb 26 10:12:41 2015 ALEXIS GIRARDEY
** Last update Sun Mar  1 16:30:41 2015 ALEXIS GIRARDEY
*/

#include <stdio.h>
#include <stdlib.h>
#include "Philosophes.h"
#include "Bol.h"
#include "actions.h"

struct s_bol	*init_bol()
{
  t_bol		*newBol;

  newBol = (t_bol *) malloc(sizeof(struct s_bol));
  newBol->bol = PLEIN;
  newBol->baguette = LIBRE;
  return (newBol);
}

struct s_philo		*init_philo(t_bol *bol, int id)
{
  t_philo	*newPhilo;

  newPhilo = (t_philo *) malloc(sizeof(struct s_philo));
  newPhilo->id = id;
  newPhilo->etat = REPOS;
  newPhilo->bol = bol;
  newPhilo->next = NULL;
}

struct s_philo		*init_table()
{
  int		i;
  t_philo	*table;
  t_philo	*temp;

  i = 1;
  table = init_philo(init_bol(), i);
  table->need_ID = i;
  temp = table;
  while (i < 8)
    {
      temp->next = init_philo(init_bol(), i + 1);
      table->need_ID = i;
      temp = temp->next;
      i++;
    }
  return (table);
}

void		lets_eat(t_philo *table)
{
  int		i;
  t_philo	*tmp;
  t_philo	*philo;

  i = 1;
  tmp = table;
  while (i < 8)
    {
      table->need_ID = i;
      philo = need_that_philo(tmp, i);
      pthread_create(&(philo->thread), NULL, philo_meca, table);
      tmp = tmp->next;
    }
}
