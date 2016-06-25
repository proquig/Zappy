//
// Created by cloquet on 14/06/16.
//

#include <player.h>
#include "server.h"

void 		right(t_server *server, t_player *player)
{
  (void)server;
  if (player->dir == UP)
    player->dir = RIGHT;
  if (player->dir == DOWN)
    player->dir = LEFT;
  if (player->dir == LEFT)
    player->dir = UP;
  if (player->dir == RIGHT)
    player->dir = DOWN;
  send_msg(server, player->fd, "ok\n");
}

void 		gauche(t_server *server, t_player *player)
{
  (void)server;
  if (player->dir == UP)
    player->dir = LEFT;
  if (player->dir == DOWN)
    player->dir = RIGHT;
  if (player->dir == LEFT)
    player->dir = DOWN;
  if (player->dir == RIGHT)
    player->dir = UP;
  send_msg(server, player->fd, "ok\n");
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
  t_action *action;

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
}

void broadcast(t_server *server, t_player *player)
{
  (void)server;
  dprintf(player->fd, "ko\n");
}

void forker(t_server *server, t_player *player)
{
    struct timeval tv;

    send_msg(server, player->fd, "ok\n");
    /*set_action_time(&tv, 600, server->param.t);*/
    update_team(server->players, player->teams.id);
}

void connect_nbr(t_server *server, t_player *player)
{
    send_msg(server, player->fd, "%i\n", player->teams.max > server->param.t ?
                                player->teams.max : server->param.t);
}

void die(t_server *server, t_player *player)
{
  (void)server;
  (void)player;
}
