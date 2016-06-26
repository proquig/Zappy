//
// Created by cloquet on 17/06/16.
//

#include "server.h"

void		print_contents_seen(t_server *server, t_player *player, int x, int y)
{
  t_player	*tmp;
  int 		i;
  int 		j;

  x = (x < 0) ? (server->param.x + x) % server->param.x : x % server->param.x;
  y = (y < 0) ? (server->param.y + y) % server->param.y : y % server->param.y;
  i = -1;
  tmp = server->players;
  while (tmp)
  	{
	  if (tmp->x == (unsigned int)x && tmp->y == (unsigned int)y && tmp->fd != -1)
		send_msg(server, player->fd, " joueur");
	  tmp = tmp->next;
	}
  while (++i < RES_SIZE)
    {
      j = -1;
      while ((unsigned int)(++j) < server->map[y][x].res.res[i])
		send_msg(server, player->fd, " %s", res_name[i]);
    }
}

void 		voir(t_server *server, t_player *player)
{
  int 		x;
  int 		y;
  int 		i;
  int 		range;

  x = (player->dir == LEFT || player->dir == UP) ? -1 : 1;
  y = (player->dir == RIGHT || player->dir == UP) ? -1 : 1;
  range = -1;
  while (++range <= player->lvl)
  {
	i = (range * -1);
	while (i <= range)
	{
	  send_msg(server, player->fd, range ? "," : "{");
	  print_contents_seen(server, player, (player->dir % 2)
										  ? (player->x - i * x)
										  : (player->x + (range * x)),
						  (player->dir % 2)
						  ? (player->y + (range * y))
						  : (player->y - i * y));
	  ++i;
	}
  }
  send_msg(server, player->fd, "}\n");
}
