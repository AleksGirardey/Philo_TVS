/*
** actions.c for Philosophes in /home/girard_x/GITREP/Philo_TVS
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Sun Mar  1 14:20:17 2015 ALEXIS GIRARDEY
** Last update Sun Mar  1 19:54:10 2015 Mathieu Chassara
*/

#include "Fct_usuelles.h"
#include "actions.h"

pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

void		philo_manger(t_philo *philosophe)
{
  philosophe->etat = MANGER;
  philosophe->bol->baguette = OCCUPE;
  philosophe->next->bol->baguette = OCCUPE;
  pthread_mutex_unlock(&g_mutex);
  printf("[Philosophe %d] My turn !\n", philosophe->id);
  sleep(EATING_TIME);
  philosophe->bol->bol = VIDE;
  printf("[Philosophe %d] Just finished to eat.\n", philosophe->id);
  pthread_mutex_lock(&g_mutex);
  philosophe->bol->baguette = LIBRE;
  philosophe->next->bol->baguette = LIBRE;
  pthread_mutex_unlock(&g_mutex);
}

void		philo_penser(t_philo *philosophe)
{
  philosophe->etat = REFLECHIR;
  philosophe->bol->baguette = OCCUPE;
  pthread_mutex_unlock(&g_mutex);
  printf("[Philosophe %d] Thinking time.\n", philosophe->id);
  sleep(THINKING_TIME);
  printf("[Philosophe %d] Meal time..\n", philosophe->id);
  while (philosophe->etat != MANGER)
    {
      pthread_mutex_lock(&g_mutex);
      if (philosophe->next->bol->baguette == LIBRE)
	philo_manger(philosophe);
      else
	pthread_mutex_unlock(&g_mutex);
    }
}

void		philo_repos(t_philo *philosophe)
{
  pthread_mutex_unlock(&g_mutex);
  if (philosophe->etat == REPOS)
    return;
  philosophe->etat = REPOS;
  printf("[Philosophe %d] Nap time.\n", philosophe->id);
  sleep(SLEEPING_TIME);
  printf("[Philosophe %d] Waking up.\n", philosophe->id);
}

void		*philo_meca(void *arg)
{
  t_philo	*philo;

  philo = (t_philo *)arg;
  printf("[Table] Philosophe %d is joining the table.\n", philo->id);
  while (philo->bol->bol == PLEIN)
    {
      pthread_mutex_lock(&g_mutex);
      if (can_eat(philo) == 1 && philo->etat != MANGER)
	philo_manger(philo);
      else if (philo->bol->baguette == LIBRE && philo->etat == REPOS)
	philo_penser(philo);
      else
	philo_repos(philo);
    }
  printf("[Table] Philosophe %d is leaving the table.\n", philo->id);
  return (NULL);
}
