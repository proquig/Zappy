//
// Created by cloquet on 17/06/16.
//

#include "server.h"

void		move_up(t_server *server, t_player *player)
{
  player->y--;
  if (player->y < 0)
    player->y = server->param.y;
}

void		move_down(t_server *server, t_player *player)
{
  player->y++;
  if (player->y < server->param.y)
    player->y = 0;
}

void		move_left(t_server *server, t_player *player)
{
  player->x--;
  if (player->x < 0)
    player->x = server->param.x;
}

void		move_right(t_server *server, t_player *player)
{
  player->x++;
  if (player->x < server->param.x)
    player->x = 0;
}


void		avance(t_server *server, t_player *player)
{
  t_avance	avance1[] = {
	  {UP, &move_up},
	  {DOWN, &move_down},
	  {LEFT, &move_left},
	  {RIGHT, &move_right},
	  {(enum Direction) -1, NULL}
  };
  int 		i;

  i = -1;
  while (avance1[++i].ptr)
    if (avance1[i].str == player->dir)
      avance1[i].ptr(server, player);
  dprintf(player->fd, "ok\n");
}