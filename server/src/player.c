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

t_player		*init_player(int fd, t_param *param)
{
  t_player		*player;
  int			i;

  i = 0;
  srand(0);
  if (!(player = malloc(sizeof(t_player))))
    return (NULL);
  player->fd = fd;
  player->x = rand() % param->x;
  player->y = rand() % param->y;
  player->dir = (enum Direction)(rand() % 4);
  player->teams.id = -1;
  player->teams.max = param->c;
  player->lvl = 1;
  player->res.res[FOOD] = 10 * 126;
  player->cmd = NULL;
  player->tab = NULL;
  init_actions(player->actions);
  while (++i < RES_SIZE)
    player->res.res[i] = 0;
  player->next = NULL;
  return (player);
}

int 			size_player(t_player *root, int team)
{
  t_player		*tmp;
  int			i;

  i = 0;
  tmp = root;
  while (tmp)
    {
      if (tmp->teams.id == team && tmp->fd != -1)
	    i++;
      tmp = tmp->next;
    }
  return (i);
}

int 			len_players(t_player *root)
{
    t_player		*tmp;
    int			i;

    i = 0;
    tmp = root;
    while (tmp)
    {
        if (tmp->fd != -1)
            i++;
        tmp = tmp->next;
    }
    return (i);
}

void			update_team(t_player *root, int id)
{
    t_player		*tmp;

    tmp = root;
    while (tmp)
    {
        if (tmp->teams.id == id)
            tmp->teams.max++;
        tmp = tmp->next;
    }
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

/*
t_player		*del_player(t_player *list, int fd)
{
    t_player		*tmp;
    t_player		*tmp1;

    if (!list)
        return (NULL);
    tmp = list;
    while (tmp->fd != fd && tmp->next &&
           tmp->next->fd != fd && (tmp = tmp->next));
    if (tmp == list)
    {
        list = list->next;
        free(tmp);
    }
    else if (tmp->next && tmp->next->fd == fd)
    {
        tmp1 = tmp->next;
        tmp->next = tmp->next->next;
        free(tmp1);
    }
    return (list);
}
*/

t_player		*del_player(t_player *players, int fd)
{
  t_player		*player;

  if ((player = search_player(players, fd)))
    player->fd = -1;
  return (players);
}

/*t_player		*del_player(t_player *list, int fd)
{
  t_player		*tmp;
  //t_player		*tmp1;

  if (!list)
	return (NULL);
  if ((tmp = search_player(list, fd)))
	tmp->fd = -1;
  //tmp->lvl
  //tmp->
 tmp = list;
  while (tmp->fd != fd && tmp->next &&
		 tmp->next->fd != fd && (tmp = tmp->next));
  if (tmp == list)
  {
	list = list->next;
	free(tmp);
  }
  else if (tmp->next && tmp->next->fd == fd)
  {
	tmp1 = tmp->next;
	tmp->next = tmp->next->next;
	free(tmp1);
  }
  return (list);

}*/
