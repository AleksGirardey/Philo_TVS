/*
** Bol.h for Philosophes in /home/girard_x/GITREP/Philo_TVS
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Thu Feb 26 10:00:44 2015 ALEXIS GIRARDEY
** Last update Sun Mar  1 20:27:45 2015 Mathieu Chassara
*/

#ifndef BOL_H_
# define BOL_H_

enum			e_sBol
  {
    VIDE, PLEIN
  };

enum			e_sBaguette
  {
    OCCUPE, LIBRE
  };

typedef struct		s_bol
{
  enum e_sBol		bol;
  enum e_sBaguette	baguette;
}			t_bol;

#endif
