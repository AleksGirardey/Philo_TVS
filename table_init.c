/*
** table_init.c for Philosophes in /home/girard_x/GITREP/Philo_TVS
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Thu Feb 26 10:12:41 2015 ALEXIS GIRARDEY
** Last update Sat Feb 28 14:31:26 2015 ALEXIS GIRARDEY
*/

#include <stdio.h>
#include <stdlib.h>
#include "Philosophes.h"
#include "Bol.h"

struct s_bol	*init_bol()
{
  t_bol		*newBol;

  newBol = (t_bol *) malloc(sizeof(struct s_bol));
  newBol->bol = PLEIN;
  newBol->baguette = LIBRE;
  return (newBol);
}

struct s_philo		*init_philo(t_bol *bol)
{
  t_philo	*newPhilo;

  newPhilo = (t_philo *) malloc(sizeof(struct s_philo));
  newPhilo->etat = REPOS;
  newPhilo->bol = bol;
  newPhilo->next = NULL;
}

struct s_philo		*init_table()
{
  int		i;
  t_philo	*table;
  t_philo	*temp;

  table = init_philo(init_bol());
  temp = table;
  i = 0;
  while (i < 7)
    {
      temp->next = init_philo(init_bol());
      temp = temp->next;
      i++;
    }
  return (table);
}

int	main()
{
  
}
