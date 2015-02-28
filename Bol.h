/*
** Bol.h for Philosophes in /home/girard_x/GITREP/Philo_TVS
** 
** Made by ALEXIS GIRARDEY
** Login   <girard_x@epitech.net>
** 
** Started on  Thu Feb 26 10:00:44 2015 ALEXIS GIRARDEY
** Last update Sat Feb 28 13:02:52 2015 ALEXIS GIRARDEY
*/

#ifndef BOL_H_
#define BOL_H_

enum	e_sBol { VIDE, PLEIN };
enum	e_sBaguette { OCCUPE, LIBRE };

typedef struct s_bol t_bol;

struct			s_bol {
  enum e_sBol		bol;
  enum e_sBaguette	baguette;
};

#endif
