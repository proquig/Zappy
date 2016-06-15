//
// Created by cloquet on 14/06/16.
//

#ifndef				ZAPPY_SERVER_PLAYER_H
# define			ZAPPY_SERVER_PLAYER_H

# include			<stdlib.h>

enum				Direction
{
  UP,
  DOWN,
  LEFT,
  RIGHT
};

typedef struct		s_ressources
{
  int 				linemate;
  int 				deraumere;
  int	 			sibur;
  int 				mendiane;
  int 				phiras;
  int				thystame;
}					t_ressources;

typedef struct		s_player
{
  unsigned int 		x;
  unsigned int 		y;
  enum Direction 	dir;
  t_ressources		ress;
  int 				fd;
  int 				team;
  int 				lvl;
  struct s_player	*next;
}					t_player;

typedef struct 		s_command
{
  char *			cmd;
  void 				(*f)();
}					t_command;

t_player			*init_player(int fd);
t_player			*add_player(t_player *list, t_player *player);
t_player			*del_player(t_player *list, t_player *player);

#endif //ZAPPY_SERVER_PLAYER_H
