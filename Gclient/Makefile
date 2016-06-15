##
## Makefile for  in /home/cloquet/PSU_2015_zappy
## 
## Made by Cloquet
## Login   <cloquet@epitech.net>
## 
## Started on  Mon Jun 13 20:20:46 2016 Cloquet
##

COMP	=	g++

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	zappy_Gclient

LDFLAGS	=	-Llib/irrlicht -Wl,-rpath,$(PWD)/lib/irrlicht -lIrrlicht

CXXFLAGS	=	-W			\
			-Wextra			\
			-Wall			\
			-std=c++11		\
			-I include/		\
			-I include/irrlicht/

all:		$(NAME)

$(NAME):	$(OBJ)
		$(COMP) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

dbg:		CFLAGS += -g
dbg:		re

shlag:		CFLAGS += -Wpedantic -Wshadow -Werror
shlag:		re
