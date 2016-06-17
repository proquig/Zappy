//
// Created by cloquet on 14/06/16.
//

#include "server.h"

void 		right(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)param;
  (void)map;
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

void 		gauche(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)param;
  (void)map;
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

void 		inventaire(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)param;
  (void)map;
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
  while (++i < RES_SIZE)
    dprintf(player->fd, "%s%s %u%s", i ? "" : "{", name[i],
	    player->res.res[i], i != (RES_SIZE - 1) ? "," : "}\n");
}

void prend(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)param;
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
  if (tab[1])
    {
      while (++i < RES_SIZE)
	if (map[player->y][player->x].res.res[i] &&
		  strcmp(tab[1], name[i]) == 0)
	      player->res.res[i] += 1;
  	dprintf(player->fd, "ok\n");
    }
  else
    dprintf(player->fd, "ko\n");
}

void pose(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)player;
  (void)param;
  (void)map;
}

void expulse(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)player;
  (void)param;
  (void)map;
}

void broadcast(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)player;
  (void)param;
  (void)map;
}

void incantation(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)player;
  (void)param;
  (void)map;
}

void forker(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)player;
  (void)param;
  (void)map;
}

void connect_nbr(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)player;
  (void)param;
  (void)map;
}

void die(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)player;
  (void)param;
  (void)map;
}
