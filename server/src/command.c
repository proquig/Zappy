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
  dprintf(player->fd, "ok\n");
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
  dprintf(player->fd, "ok\n");
}

void 		inventaire(t_server *server, t_player *player)
{
  char 		*name[] = {
	  "nourriture",
	  "linemate",
	  "deraumere",
	  "sibur",
	  "mendiane",
	  "phiras",
	  "thystame",
  };
  int 		i;

  i = -1;
  (void)server;
  while (++i < RES_SIZE)
    dprintf(player->fd, "%s%s %u%s", i ? "" : "{", name[i],
	    player->res.res[i], i != (RES_SIZE - 1) ? "," : "}\n");
}

void		prend(t_server *server, t_player *player)
{
  char 		*name[] = {
	  "nourriture",
	  "linemate",
	  "deraumere",
	  "sibur",
	  "mendiane",
	  "phiras",
	  "thystame",
  };
  int 		i;
  int 		err;

  err = 1;
  i = -1;
  if (server->tab[1])
    {
      while (++i < RES_SIZE)
	if (server->map[player->y][player->x].res.res[i] &&
		  strcmp(server->tab[1], name[i]) == 0)
	  {
	    server->map[player->y][player->x].res.res[i] -= 1;
	    player->res.res[i] += 1;
	    err = 0;
	  }
    }
  dprintf(player->fd, err ? "ko\n" : "ok\n");
}

void 		pose(t_server *server, t_player *player)
{
  char 		*name[] = {
	  "nourriture",
	  "linemate",
	  "deraumere",
	  "sibur",
	  "mendiane",
	  "phiras",
	  "thystame",
  };
  int 		i;
  int 		err;

  err = 1;
  i = -1;
  if (server->tab[1])
    {
      while (++i < RES_SIZE)
	if (player->res.res[i] && strcmp(server->tab[1], name[i]) == 0)
	  {
	    server->map[player->y][player->x].res.res[i] += 1;
	    player->res.res[i] -= 1;
	    err = 0;
	  }
    }
  dprintf(player->fd, err ? "ko\n" : "ok\n");
}

void broadcast(t_server *server, t_player *player)
{
  (void)server;
  (void)player;
}

void incantation(t_server *server, t_player *player)
{
  (void)server;
  (void)player;
}

void forker(t_server *server, t_player *player)
{
  (void)server;
  (void)player;
}

void connect_nbr(t_server *server, t_player *player)
{
  (void)server;
  (void)player;
}

void die(t_server *server, t_player *player)
{
  (void)server;
  (void)player;
}
