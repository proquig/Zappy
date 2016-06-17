/*
** player.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server/src
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Wed Jun 15 13:55:08 2016 Guillaume PROQUIN
** Last update Wed Jun 15 14:14:28 2016 Guillaume PROQUIN
*/

#include "server.h"

t_player		*init_player(int fd)
{
  t_player	*player;

  srand(0);
  if (!(player = malloc(sizeof(t_player))))
    return (NULL);
  player->fd = fd;
  player->x = 0;
  player->y = 0;
  player->dir = (enum Direction)(rand() % 4);
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

t_player		*search_player(t_player *list, int fd)
{
  t_player		*tmp;

  if (!list)
	return (NULL);
  tmp = list;
  while (tmp->fd != fd && (tmp = tmp->next));
  return (tmp ? tmp : NULL);
}

t_player		*del_player(t_player *list, int fd)
{
  t_player		*tmp;

  if (!list)
    return (NULL);
  tmp = search_player(list, fd);
  if (tmp == list)
	list = list->next;
  else if (tmp && tmp->next && tmp->next->fd == fd)
	tmp->next = tmp->next->next;
  if (tmp)
  	free(tmp);
  return (tmp == list ? NULL : list);
}
