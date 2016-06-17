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
  void 				(*f)(char **tab, t_player *player, t_param *param, t_square **map);
}				t_command;

t_player			*init_player(int fd);
t_player			*add_player(t_player *list, t_player *player);
t_player			*del_player(t_player *list, int fd);
t_player			*search_player(t_player *list, int fd);
void 				avance(char **tab, t_player *player, t_param *param, t_square **map);
void 				right(char **tab, t_player *player, t_param *param, t_square **map);
void 				gauche(char **tab, t_player *player, t_param *param, t_square **map);
void 				voir(char **tab, t_player *player, t_param *param, t_square **map);
void 				inventaire(char **tab, t_player *player, t_param *param, t_square **map);
void 				prend(char **tab, t_player *player, t_param *param, t_square **map);
void 				pose(char **tab, t_player *player, t_param *param, t_square **map);
void 				expulse(char **tab, t_player *player, t_param *param, t_square **map);
void 				broadcast(char **tab, t_player *player, t_param *param, t_square **map);
void 				incantation(char **tab, t_player *player, t_param *param, t_square **map);
void 				forker(char **tab, t_player *player, t_param *param, t_square **map);
void 				connect_nbr(char **tab, t_player *player, t_param *param, t_square **map);
void 				die(char **tab, t_player *player, t_param *param, t_square **map);

#endif //ZAPPY_SERVER_PLAYER_H
