/*
** actions.h for Philosophes in /home/girard_x/GITREP/Philo_TVS
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Sun Mar  1 14:19:52 2015 ALEXIS GIRARDEY
** Last update Sun Mar  1 19:25:09 2015 ALEXIS GIRARDEY
*/

#ifndef ACTIONS_H_
#define	ACTIONS_H_

#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "Philosophes.h"
#include "Bol.h"

extern	pthread_mutex_t	mutex;

#define EATING_TIME 3
#define THINKING_TIME 3
#define SLEEPING_TIME 3

void	philo_manger(t_philo *philosophe);
void	philo_penser(t_philo *philosophe);
void	philo_repos(t_philo *philosophe);
void	*philo_meca(void *arg);

#endif
