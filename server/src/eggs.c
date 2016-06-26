//
// Created by cloque_b on 26/06/16.
//

#include "server.h"

t_eggs			*init_eggs(int x, int y, t_team team, int frequency)
{
    t_eggs		*new;

    if (!(new = malloc(sizeof(t_eggs))))
        return (NULL);
    new->x = x;
    new->y = y;
    new->team.id = team.id;
    new->team.max = team.max + 1;
    set_action_time(&new->val, 600, frequency);
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

int			they_are_eggs(t_server *server, int team_id)
{
    t_eggs		*tmp;

    tmp = server->eggs;
    while (tmp)
    {
        if (tmp->team.id == team_id)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

