##
## Makefile for  in /home/cloquet/PSU_2015_zappy
## 
## Made by Cloquet
## Login   <cloquet@epitech.net>
## 
## Started on  Mon Jun 13 20:20:46 2016 Cloquet
##

COMP	=	g++

SRC	=	src/main.cpp	\
		src/GUI.cpp		\
		src/Board.cpp	\
		src/GPlayer.cpp	\
		src/GMap.cpp	\
		src/Tool.cpp	\
		src/Mutex.cpp	\
		src/Egg.cpp		\
		src/EventReceiver.cpp	\
		src/GCommunicator.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	zappy_Gclient

LDFLAGS	=	-Llib/irrlicht -Wl,-rpath,$(PWD)/lib/irrlicht -lIrrlicht	\
			-lpthread

CXXFLAGS	=	-W			\
			-Wextra			\
			-std=c++11		\
			-I include/		\
			-I ../common/include/	\
			-I include/irrlicht/

all:		$(NAME)

$(NAME):	$(OBJ)
		$(COMP) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

dbg:		CFLAGS += -g
dbg:		re

shlag:		CFLAGS += -Wpedantic -Wshadow -Werror
shlag:		re
