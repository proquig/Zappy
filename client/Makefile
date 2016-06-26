##
## Makefile for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client
## 
## Made by jacque_x
## Login   <jacque_x@epitech.net>
## 
## Started on  Wed Jun 15 16:53:16 2016 jacque_x
## Last update Sun Jun 26 11:32:35 2016 jacque_x
##

SRC     =       src/main.cpp		\
		src/utils.cpp		\
		src/Client.cpp		\
		src/think.cpp		\
		src/action.cpp		\
		src/get_command.cpp	\
		src/SocketBuf.cpp	\
		src/IA.cpp

OBJ     =       $(SRC:.cpp=.o)

NAME    =       zappy_ai

CXXFLAGS  =      -W -Wextra -Wall -I include/ -std=c++11

all:        	$(NAME)

$(NAME):        $(OBJ)
		g++ -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:             fclean all

dbg:            CXXFLAGS += -g
dbg:            re

shlag:          CXXFLAGS += -Wpedantic -Wshadow -Werror
shlag:          re
