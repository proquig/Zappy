/*
** avance.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 09:55:21 2016 Guillaume PROQUIN
** Last update Sun Jun 26 11:02:05 2016 Guillaume PROQUIN
*/

#include "server.h"
#include "mon_cmd.h"

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
    player->x = (player->x == 0) ? (server->param.x - 1) : player->x - 1;
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
  while (avance1[++i].ptr)
    if (avance1[i].str == player->dir)
      avance1[i].ptr(server, player);
  send_msg(server, player->fd, "ok\n");
  player->notify = 1;
  notify(server, "ppo");
  player->notify = 0;
}
