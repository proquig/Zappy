/*
** command_other.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 11:46:17 2016 Guillaume PROQUIN
** Last update Sun Jun 26 13:07:43 2016 Guillaume PROQUIN
*/

#include "server.h"

void		free_cmds(t_player *player)
{
  if (player->cmd)
    free(player->cmd);
  if (player->tab)
    free(player->tab);
  player->cmd = NULL;
  player->tab = NULL;
}

void		broadcast(t_server *server, t_player *player)
{
  (void)server;
  send_msg(server, player->fd, "ko\n");
}

void		forker(t_server *server, t_player *player)
{
  send_msg(server, player->fd, "ok\n");
  server->eggs = add_egg(server->eggs,
			 init_eggs(player->x, player->y, player->teams));
  update_team(server->players, player->teams.id);
}
