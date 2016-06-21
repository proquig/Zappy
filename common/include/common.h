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
  UP,
  LEFT,
  DOWN,
  RIGHT
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
}			t_ressources;

typedef struct		s_player
{
  unsigned int 		x;
  unsigned int 		y;
  enum Direction 	dir;
  t_ressources		res;
  int 		    	fd;
  int 	    		team;
  int   			lvl;
//    t_action        *action;
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

extern const char 		*res_name[];

#endif
