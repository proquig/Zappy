##
## Makefile for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client
## 
## Made by jacque_x
## Login   <jacque_x@epitech.net>
## 
## Started on  Wed Jun 15 16:53:16 2016 jacque_x
## Last update Fri Jun 17 19:13:24 2016 jacque_x
##

SRC     =       src/main.cpp		\
		src/utils.cpp		\
		src/Client.cpp		\
		src/get_command.cpp	\
		src/IA.cpp

OBJ     =       $(SRC:.cpp=.o)

NAME    =       zappy_ai

CXXFLAGS  =       -W -Wextra -Wall -I include/ -std=c++11

all:        	$(NAME)

$(NAME):        $(OBJ)
		g++ -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:             fclean all

dbg:            CFLAGS += -g
dbg:            re

shlag:          CFLAGS += -Wpedantic -Wshadow -Werror
shlag:          re
