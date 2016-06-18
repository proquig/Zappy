//
// Created by cloquet on 17/06/16.
//

#include "server.h"

void		print_contents_seen(t_server *server, t_player *player, int x, int y)
{
  t_player	*tmp;
  int 		i;
  int 		j;

  x = (x < 0) ? (server->param.x + x) : (x % server->param.x);
  y = (y < 0) ? (server->param.y + y) : (y % server->param.y);
  i = -1;
  tmp = server->players;
  while (tmp)
  	{
	  if (tmp->x == (unsigned int)x && tmp->y == (unsigned int)y)
		dprintf(player->fd, " joueur");
	  tmp = tmp->next;
	}
  while (++i < RES_SIZE)
    {
      j = -1;
      while ((unsigned int)(++j) < server->map[y][x].res.res[i])
		dprintf(player->fd, " %s", res_name[j]);
    }
}

void 		voir(t_server *server, t_player *player)
{
  int 		i;
  int 		range;
  int 		dir;

  dir = (player->dir == LEFT || player->dir == DOWN) ? -1 : 1;
  range = -1;
  while (++range <= player->lvl)
  	{
	  i = (range * -1);
	  while (i++ <= range)
	    {
	      dprintf(player->fd, range ? "," : "{");
	      print_contents_seen(server, player, (player->dir % 2)
					 ? (player->x + (range * dir)) : (player->x + i),
				  (player->dir % 2)
				  ? (player->y + (range * dir)) : (player->y + i));
	    }
  	}
  dprintf(player->fd, "}\n");
}
