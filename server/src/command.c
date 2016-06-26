/*
** command.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 09:55:56 2016 Guillaume PROQUIN
** Last update Sun Jun 26 11:45:55 2016 Guillaume PROQUIN
*/

#include "player.h"
#include "mon_cmd.h"
#include "server.h"

void 		right(t_server *server, t_player *player)
{
  (void)server;
  player->dir = player->dir % 4 + 1;
  send_msg(server, player->fd, "ok\n");
  player->notify = 1;
  notify(server, "ppo");
  player->notify = 0;
}

void 		gauche(t_server *server, t_player *player)
{
  (void)server;
  player->dir = (player->dir - 1 + 4 - 1) % 4 + 1;
  send_msg(server, player->fd, "ok\n");
  player->notify = 1;
  notify(server, "ppo");
  player->notify = 0;
}

void 		inventaire(t_server *server, t_player *player)
{
  int 		i;

  i = -1;
  (void)server;
  while (++i < RES_SIZE)
    send_msg(server, player->fd, "%s%s %u%s", i ? "" : "{", res_name[i],
	     player->res.res[i], i != (RES_SIZE - 1) ? "," : "}\n");
}

void		prend(t_server *server, t_player *player)
{
  int 		i;
  int 		err;
  t_action	*action;

  err = 1;
  i = -1;
  action = get_current_action(player->actions);
  if (action && action->cmd && action->cmd[1])
    {
      while (++i < RES_SIZE)
	if (server->map[player->y][player->x].res.res[i]
	    && !strcmp(action->cmd[1], res_name[i]))
	  {
	    server->map[player->y][player->x].res.res[i] -= 1;
	    player->res.res[i] += i ? 1 : 126;
	    err = 0;
	  }
    }
  send_msg(server, player->fd, err ? "ko\n" : "ok\n");
  if (!err)
    {
      player->notify = 1;
      notify(server, "pgt");
      player->notify = 0;
    }
}

void 		pose(t_server *server, t_player *player)
{
  int 		i;
  int 		err;
  t_action	*action;

  err = 1;
  i = -1;
  action = get_current_action(player->actions);
  if (action && action->cmd && action->cmd[1])
    {
      while (++i < RES_SIZE)
	if (((i && player->res.res[i]) || (!i && player->res.res[i] >= 126))
	    && !strcmp(action->cmd[1], res_name[i]))
	  {
	    server->map[player->y][player->x].res.res[i] += 1;
	    player->res.res[i] -= i ? 1 : 126;
	    err = 0;
	  }
    }
  send_msg(server, player->fd, err ? "ko\n" : "ok\n");
  if (!err)
    {
      player->notify = 1;
      notify(server, "pdr");
      player->notify = 0;
    }
}
