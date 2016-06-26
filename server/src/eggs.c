/*
** eggs.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 22:09:41 2016 Guillaume PROQUIN
** Last update Sun Jun 26 22:10:00 2016 Guillaume PROQUIN
*/

#include "server.h"

t_eggs			*init_eggs(unsigned int x, unsigned int y, t_team team)
{
  t_eggs		*new;

  if (!(new = malloc(sizeof(t_eggs))))
    return (NULL);
  new->x = x;
  new->y = y;
  new->team.id = team.id;
  new->team.max = team.max + 1;
  new->next = NULL;
  return (new);
}

t_player		*init_player_from_eggs(int fd, t_eggs *egg)
{
  t_player		*player;

  if (!(player = malloc(sizeof(t_player))))
    return (NULL);
  player->fd = fd;
  player->x = egg->x;
  player->y = egg->y;
  player->dir = (enum Direction)(rand() % 4);
  player->teams.id = egg->team.id;
  player->teams.max = egg->team.max;
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

t_eggs			*add_egg(t_eggs *list, t_eggs *player)
{
  t_eggs		*tmp;

  if (!list && !player)
    return (NULL);
  if (!list)
    return (player);
  tmp = list;
  while (tmp->next && (tmp = tmp->next));
  tmp->next = player;
  return (list);
}

int			they_are_eggs(t_server *server)
{
  t_eggs		*tmp;
  int		        i;

  i = 0;
  tmp = server->eggs;
  while (tmp)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}
