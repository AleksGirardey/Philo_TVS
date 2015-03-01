/*
** actions.c for Philosophes in /home/girard_x/GITREP/Philo_TVS
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Sun Mar  1 14:20:17 2015 ALEXIS GIRARDEY
** Last update Sun Mar  1 19:40:24 2015 ALEXIS GIRARDEY
*/

#include "Fct_usuelles.h"
#include "actions.h"

pthread_mutex_t		mutex = PTHREAD_MUTEX_INITIALIZER;

void		philo_manger(t_philo *philosophe)
{
  philosophe->etat = MANGER;
  philosophe->bol->baguette = OCCUPE;
  philosophe->next->bol->baguette = OCCUPE;
  pthread_mutex_unlock(&mutex);
  printf("[Philosophe %d] Aaahh, enfin mon tour de manger.\n", philosophe->id);
  sleep(EATING_TIME);
  philosophe->bol->bol = VIDE;
  printf("[Philosophe %d] Finalement, c'est bon le riz.\n", philosophe->id);
  pthread_mutex_lock(&mutex);
  philosophe->bol->baguette = LIBRE;
  philosophe->next->bol->baguette = LIBRE;
  pthread_mutex_unlock(&mutex);
}

void		philo_penser(t_philo *philosophe)
{
  philosophe->etat = REFLECHIR;
  philosophe->bol->baguette = OCCUPE;
  pthread_mutex_unlock(&mutex);
  printf("[Philosophe %d] Je pense donc je suis...\n", philosophe->id);
  sleep(THINKING_TIME);
  printf("[Philosophe %d] Non mais en faite j'ai faim.\n", philosophe->id);
  while (philosophe->etat != MANGER)
    {
      pthread_mutex_lock(&mutex);
      if (philosophe->next->bol->baguette == LIBRE)
	philo_manger(philosophe);
      else
	pthread_mutex_unlock(&mutex);
    }
}

void		philo_repos(t_philo *philosophe)
{
  pthread_mutex_unlock(&mutex);
  if (philosophe->etat == REPOS)
    return;
  philosophe->etat = REPOS;
  printf("[Philosophe %d] Wouaaaaah, c'est partit pour la sieste !\n", philosophe->id);
  sleep(SLEEPING_TIME);
  printf("[Philosophe %d] *s'étire* huuuum, j'ai bien dormi !\n", philosophe->id);
}

void		*philo_meca(void *arg)
{
  t_philo	*philo;

  philo = (t_philo *)arg;
  printf("[Table] Philosophe %d rejoint la table\n", philo->id);
  while (philo->bol->bol == PLEIN)
    {
      pthread_mutex_lock(&mutex);
      if (can_eat(philo) == 1 && philo->etat != MANGER)
	philo_manger(philo);
      else if (philo->bol->baguette == LIBRE && philo->etat == REPOS)
	philo_penser(philo);
      else
	philo_repos(philo);
    }
  printf("[Table] Philosophe %d quitte la table\n", philo->id);
  return (NULL);
}
