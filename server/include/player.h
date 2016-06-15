//
// Created by cloquet on 14/06/16.
//

#ifndef ZAPPY_SERVER_PLAYER_H
#define ZAPPY_SERVER_PLAYER_H

enum			Direction
{
  UP,
  DOWN,
  RIGHT,
  LEFT
};

typedef struct		s_ressources
{
  int 			linemate;
  int 			deraumere;
  int	 		sibur;
  int 			mendiane;
  int 			phiras;
  int			thystame;
}			t_ressources;

typedef struct		s_player
{
  unsigned int 		x;
  unsigned int 		y;
  enum Direction 	dir;
  t_ressources		ress;
  int 			fd;
  int 			team;
  int 			lvl;
  t_player		*next;
}			t_player;

typedef struct 		s_command
{
  char *		cmd;
  void 			(*f)();
}			t_command;
#endif //ZAPPY_SERVER_PLAYER_H
