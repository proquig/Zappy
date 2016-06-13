##
## Makefile for  in /home/cloquet/PSU_2015_zappy
## 
## Made by Cloquet
## Login   <cloquet@epitech.net>
## 
## Started on  Mon Jun 13 20:20:46 2016 Cloquet
## Last update Mon Jun 13 20:34:20 2016 Cloquet
##

SRC	=	src/main.c		\
		src/set_params.c	\
		src/utils.c

OBJ	=	$(SRC:.c=.o)

NAME	=	zappy_server

CFLAGS	=	-W -Wextra -Wall -g -I include/

all:		$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
