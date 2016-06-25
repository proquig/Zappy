//
// Created by cloquet on 17/06/16.
//
//

#include "server.h"

void		move_up(t_server *server, t_player *player)
{
  player->y = (player->y == 0) ? (server->param.y - 1) : player->y - 1;
}

void		move_down(t_server *server, t_player *player)
{
  player->y = (player->y + 1 == server->param.y) ? 0 : player->y + 1;
}

void		move_left(t_server *server, t_player *player)
{
    player->x = (player->x - 1 == 0) ? (server->param.x - 1) : player->x - 1;
}

void		move_right(t_server *server, t_player *player)
{
    player->x = (player->x + 1 == server->param.x) ? 0 : player->x + 1;
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
//    fprintf(stderr, "BEFORE => %i %i\n", player->x, player->y);
  while (avance1[++i].ptr)
    if (avance1[i].str == player->dir)
      avance1[i].ptr(server, player);
  //  fprintf(stderr, "Player nb : %i y=%i x=%i\n", player->fd, player->y, player->x);
  send_msg(server, player->fd, "ok\n");
}