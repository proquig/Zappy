/*
** command_other.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 11:46:17 2016 Guillaume PROQUIN
** Last update Sun Jun 26 11:46:47 2016 Guillaume PROQUIN
*/

#include "server.h"

void		broadcast(t_server *server, t_player *player)
{
  (void)server;
  dprintf(player->fd, "ko\n");
}

void			forker(t_server *server, t_player *player)
{
  struct timeval	tv;

  send_msg(server, player->fd, "ok\n");
  /*set_action_time(&tv, 600, server->param.t);*/
  update_team(server->players, player->teams.id);
}
