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
  size_t 		x;
  size_t 		y;
  enum Direction 	dir;
  t_ressources		ress;
  int 			fd;
  int 			team;
}			t_player;

#endif //ZAPPY_SERVER_PLAYER_H
