//
// Created by cloquet on 17/06/16.
//

#include "server.h"

void print_contents_seen(int fd, int x, int y, t_square **map)
{
  char *name[] = {
	  "nourriture",
	  "linemate",
	  "deraumere",
	  "sibur",
	  "mendiane",
	  "phiras",
	  "thystame",
  };
  int i;
  unsigned int j;

  i = -1;
  dprintf(fd, ",");
  while (++i < RES_SIZE)
    {
      j = 0;
      while (j < map[y][x].res.res[i])
	{
	  dprintf(fd, " %s", name[i]);
	  j++;
	}
    }
}

void voir(char **tab, t_player *player, t_param *param, t_square **map)
{
  int lvl;

  lvl = 0;
  (void)tab;
  (void)param;
  dprintf(player->fd, "{ joueur");
  while (lvl > player->lvl)
    {
      print_contents_seen(player->fd, player->x, player->y, map);
      lvl++;
    }
  dprintf(player->fd, " }\n");
}
