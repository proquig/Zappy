/*
** player.h for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server/include
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Wed Jun 15 14:17:25 2016 Guillaume PROQUIN
** Last update Wed Jun 15 14:17:27 2016 Guillaume PROQUIN
*/

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

enum 				RESSOURCES
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
}					t_ressources;

typedef struct		s_player
{
  unsigned int 		x;
  unsigned int 		y;
  enum Direction 	dir;
  t_ressources		res;
  int 				fd;
  int 				team;
  int 				lvl;
  struct s_player	*next;
}					t_player;

typedef struct 		s_command
{
  char *			cmd;
  char *			sec;
  void 				(*f)();
}				t_command;

t_player			*init_player(int fd);
t_player			*add_player(t_player *list, t_player *player);
t_player			*del_player(t_player *list, int fd);
t_player			*search_player(t_player *list, int fd);
void 			avance();
void 			move_right();
void 			gauche();
void 			voir();
void 			inventaire();
void 			prend();
void 			pose();
void 			expulse();
void 			broadcast();
void 			incantation();
void 			forker();
void 			connect_nbr();
void 			die();


#endif //ZAPPY_SERVER_PLAYER_H
