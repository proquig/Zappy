/*
** common.h for zappy in /home/proqui_g/rendu/PSU_2015_zappy/common/include
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Fri Jun 17 19:13:22 2016 Guillaume PROQUIN
** Last update Fri Jun 17 19:14:18 2016 Guillaume PROQUIN
*/

#ifndef			__ZAPPY_SERVER_COMMON_H__
# define		__ZAPPY_SERVER_COMMON_H__

enum			Direction
{
  UP = 1,
  RIGHT = 2,
  DOWN = 3,
  LEFT = 4
};

enum 			RESSOURCES
{
  FOOD,
  LINEMATE,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME,
  RES_SIZE
};

typedef struct		s_ressources
{
  unsigned int 		res[RES_SIZE];
  int			notify[RES_SIZE];
}			t_ressources;

typedef struct          s_team
{
    int                 id;
    int                 max;
}                       t_team;

typedef struct 		s_server t_server;
typedef struct 		s_player t_player;
typedef struct 		s_action t_action;

typedef struct		s_action
{
  void 			(*f)(t_server *server, t_player *player);
  char			**cmd;
  struct timeval	time;
  char 			exec;
}               	t_action;

typedef struct      s_eggs
{
    unsigned int             x;
    unsigned int             y;
    t_team          team;
    struct s_eggs   *next;
}                   t_eggs;

typedef struct		s_player
{
  unsigned int 		x;
  unsigned int 		y;
  enum Direction 	dir;
  t_ressources		res;
  int 		    	fd;
  int   		lvl;
  int			notify;
  int			param[2];
  char 			*cmd;
  char 			**tab;
  t_action		actions[10];
  t_team		teams;
  struct s_player	*next;
}			t_player;

typedef struct		s_square
{
  unsigned int		x;
  unsigned int		y;
  unsigned int		size_x;
  unsigned int		size_y;
  t_ressources		res;
  t_player		*players;
}			t_square;

typedef struct		s_incantation
{
  int             	nb_player;
  unsigned int 		res[RES_SIZE];
}			t_incantation;

extern const char 	*res_name[];

#endif
