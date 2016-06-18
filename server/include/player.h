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
# include			"common.h"

typedef struct 		s_command
{
  char *			cmd;
  char *			sec;
  void 				(*f)(t_server *server, t_player *player);
}					t_command;

t_player			*init_player(int fd);
t_player			*add_player(t_player *list, t_player *player);
t_player			*del_player(t_player *list, int fd);
t_player			*search_player(t_player *list, int fd);

void 				avance(t_server *server, t_player *player);
void 				right(t_server *server, t_player *player);
void 				gauche(t_server *server, t_player *player);

char				*print_contents_seen(t_param *param, int x, int y, t_square **map);
void 				voir(t_server *server, t_player *player);
void 				inventaire(t_server *server, t_player *player);
void 				prend(t_server *server, t_player *player);
void 				pose(t_server *server, t_player *player);
void 				expulse(t_server *server, t_player *player);
void 				broadcast(t_server *server, t_player *player);
void 				incantation(t_server *server, t_player *player);
void 				forker(t_server *server, t_player *player);
void 				connect_nbr(t_server *server, t_player *player);
void 				die(t_server *server, t_player *player);

#endif //ZAPPY_SERVER_PLAYER_H
