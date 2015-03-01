/*
** Fct_usuelles.h for Philosophes in /home/girard_x/GITREP/Philo_TVS
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Sat Feb 28 14:32:14 2015 ALEXIS GIRARDEY
** Last update Sun Mar  1 16:03:23 2015 ALEXIS GIRARDEY
*/

#ifndef FCT_USUELLES_H_
#define FCT_USUELLES_H_

#include "Philosophes.h"
#include "Bol.h"

int	nb_bols_plein(t_philo *table);
int	can_eat(t_philo *table, int id_philo);
int	check_B(t_philo *table, int id_philo);
struct s_philo	*need_that_philo(t_philo *table, int id);

#endif
