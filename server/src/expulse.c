/*
** expulse.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 11:01:11 2016 Guillaume PROQUIN
** Last update Sun Jun 26 11:01:13 2016 Guillaume PROQUIN
*/

#include "player.h"

static t_expulse	push[] = {
  {UP, 5},
  {DOWN, 1},
  {LEFT, 3},
  {RIGHT, 7}
};

void			expulse_player(t_player *player, t_player *victim, t_server*server)
{
  t_avance		avance[] = {
    {UP,    &move_up},
    {DOWN,  &move_down},
    {LEFT,  &move_left},
    {RIGHT, &move_right},
    {0, NULL},
  };
  int 		i;

  i = -1;
  while (avance[++i].ptr)
    if (avance[i].str == player->dir)
      avance[i].ptr(server, victim);
}

void			expulse(t_server *server, t_player *player)
{
  t_player		*tmp;
  int			i;
  int			err;

  err = 1;
  tmp = server->players;
  while (tmp)
    {
      if (tmp->x == player->x && tmp->y == player->y && tmp != player)
	{
	  i = -1;
	  while (++i < 4)
	    if (tmp->dir == push[i].dir)
	      {
		expulse_player(player, tmp, server);
		send_msg(server, tmp->fd, "deplacement: %u\n", push[i].pos);
	      }
	  err = 0;
	}
      tmp = tmp->next;
    }
  send_msg(server, player->fd, err ? "ko\n" : "ok\n");
}
