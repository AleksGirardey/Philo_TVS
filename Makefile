##
## Makefile for Philosophes in /home/girard_x/GITREP/Philo_TVS
## 
## Made by ALEXIS GIRARDEY
## Login   <girard_x@epitech.net>
## 
## Started on  Thu Feb 26 09:21:32 2015 ALEXIS GIRARDEY
## Last update Sat Feb 28 12:54:08 2015 ALEXIS GIRARDEY
##

NAME	= philo

CC	= gcc

RM	= rm -rvf

CFLAGS	= -lpthread

SRC	= table_init.c

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

auteur:
	$(shell echo "chassa_m;girard_x" >> auteur)

.PHONY: all re clean fclean
