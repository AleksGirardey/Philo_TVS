/*
** Philosophes.h for Philosophes in /home/girard_x/GITREP/Philo_TVS
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Thu Feb 26 09:39:02 2015 ALEXIS GIRARDEY
** Last update Sun Mar  1 16:16:37 2015 ALEXIS GIRARDEY
*/

#ifndef PHILOSOPHES_H_
#define PHILOSOPHES_H_

#include <pthread.h>
#include "Bol.h"

enum			e_etat {REFLECHIR, MANGER, REPOS};

typedef struct s_philo t_philo;

struct			s_philo {
  int			id;
  int			need_ID;
  enum e_etat		etat;
  pthread_t		thread;
  t_bol			*bol;
  struct s_philo	*next;
};

#endif
