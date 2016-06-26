/*
** player.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server/src
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Wed Jun 15 13:55:08 2016 Guillaume PROQUIN
** Last update Sun Jun 26 11:40:29 2016 Guillaume PROQUIN
*/

#include "server.h"

void 			init_player_res(t_player *player)
{
  int 			i;

  i = -1;
  while (++i < RES_SIZE)
    {
      player->res.res[i] = i ? 0 : 10 * 126;
      player->res.notify[i] = 0;
    }
}

t_player		*init_player(int fd, t_param *param)
{
  static int	x = 0;
  t_player		*player;

  x = (x + 1) % 1024;
  if (!(player = malloc(sizeof(t_player))))
    return (NULL);
  player->fd = fd;
  player->x = (rand() * ++x) % param->x;
  player->y = (rand() ^ ++x) % param->y;
  player->dir = (enum Direction)(rand() % 4);
  player->teams.id = -1;
  player->teams.max = param->c;
  player->lvl = 1;
  player->notify = 0;
  player->param[0] = -1;
  player->param[1] = -1;
  player->cmd = NULL;
  player->tab = NULL;
  init_actions(player->actions);
  init_player_res(player);
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
  return (tmp);
}

t_player		*del_player(t_player *players, int fd)
{
  t_player		*player;

  if ((player = search_player(players, fd)))
    {
      if (player->teams.id == GRAPHIC)
	player->teams.id = -1;
      player->fd = -1;
    }
  return (players);
}
