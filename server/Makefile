##
## Makefile for  in /home/cloquet/PSU_2015_zappy
## 
## Made by Cloquet
## Login   <cloquet@epitech.net>
## 
## Started on  Mon Jun 13 20:20:46 2016 Cloquet
## Last update Wed Jun 22 13:33:13 2016 Guillaume PROQUIN
##

SRC	=	src/main.c		\
		src/set_params.c	\
		src/init_server.c	\
		src/player.c		\
		src/utils.c		\
		src/analyse_commande.c	\
		src/command.c		\
		src/avance.c		\
		src/expulse.c		\
		src/voir.c		\
		src/map.c		\
		src/mon_cmd.c		\
		src/free.c		\
		src/action.c		\
		src/handle_time.c	\
		src/client.c		\
		src/elevation.c		\
		src/get_next_line.c \
		../common/src/common.c

OBJ	=	$(SRC:.c=.o)

NAME	=	zappy_server

CFLAGS	=	-W -Wextra -Wall -I include/ -I ../common/include/

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
