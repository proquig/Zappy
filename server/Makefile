##
## Makefile for  in /home/cloquet/PSU_2015_zappy
## 
## Made by Cloquet
## Login   <cloquet@epitech.net>
## 
## Started on  Mon Jun 13 20:20:46 2016 Cloquet
##

SRC	=	src/main.c		\
		src/set_params.c	\
		src/init_server.c	\
		../common/src/player.c		\
		src/utils.c		\
		src/analyse_commande.c	\
		src/command.c		\
		src/avance.c		\
		../common/src/map.c

OBJ	=	$(SRC:.c=.o)

NAME	=	zappy_server

CFLAGS	=	-W -Wextra -Wall -I include/

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

dbg:		CFLAGS += -g
dbg:		re

shlag:		CFLAGS += -Wpedantic -Wshadow -Werror
shlag:		re
