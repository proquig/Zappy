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
  int j;

  x = (x < 0) ? (map[0][0].size_x + x) : (x % map[0][0].size_x);
  y = (y < 0) ? (map[0][0].size_y + y) : (y % map[0][0].size_y);
  i = -1;
  while (++i < RES_SIZE)
    {
      j = -1;
      while ((unsigned int)(++j) < map[y][x].res.res[i]);
		dprintf(fd, " %s", map[y][x].res.res[i]);
    }
}

void voir(char **tab, t_player *player, t_param *param, t_square **map)
{
  int i;
  int range;
  int dir;

  (void)tab;
  dir = (player->dir == LEFT || player->dir == DOWN) ? -1 : 1;
  range = -1;
  while (++range <= player->lvl)
  	{
	  i = (range * -1);
	  while (i++ <= range)
	    {
		  if (player->dir % 2)
		    str = print_contents_seen(param, player->x + (range * dir),
									  player->y + i, map);
		  else
		    str = print_contents_seen(param, player->x + i,
									  player->y + (range * dir), map);
		  dprintf(player->fd, "%s%s%s", (range ? "" : "{"), str,
				  i == player->lvl ? "}" : ",");
	    }
  	}
}
