/*
** player.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server/src
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Wed Jun 15 13:55:08 2016 Guillaume PROQUIN
** Last update Wed Jun 15 13:55:11 2016 Guillaume PROQUIN
*/

#include "player.h"

t_player		*init_player(int fd)
{
  t_player	*player;

  if (!(player = malloc(sizeof(t_player))))
	return (NULL);
  player->fd = fd;
  player->x = 0;
  player->y = 0;
  player->dir = UP; // TODO: rand
  player->team = -1;
  player->lvl = 0;
  player->next = NULL;
  return (player);
}

t_player		*add_player(t_player *list, t_player *player)
{
  t_player		*tmp;

  if (!list && !player)
	return (NULL);
  if (!list)
	return (player);
  tmp = list;
  while (tmp->next && (tmp = tmp->next));
  tmp->next = player;
  return (list);
}

t_player		*del_player(t_player *list, t_player *player)
{
  t_player		*tmp;
  if (!list || !player)
	return (NULL);
  tmp = list;
  while (tmp != player && tmp->next != player && (tmp = tmp->next));
  if (tmp == player)
	return (player->next);
  if (tmp->next == player)
  	{
	  tmp->next = player->next;
	  free(player);
  	}
  return (list);
}
