/*
** events.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 11:28:28 2016 Guillaume PROQUIN
** Last update Sun Jun 26 11:29:59 2016 Guillaume PROQUIN
*/

#include "mon_cmd.h"

const t_cmd	events[] = {
  {"pdi", 0, &event_pdi},
  {"pnw", 0, &event_pnw},
  {"ppo", 0, &event_ppo},
  {"pdr", 0, &event_pdr},
  {"pgt", 0, &event_pgt},
  {NULL, 0, NULL}
};

int		event_pdi(t_server *server, t_player *player)
{
  int 		i;
  t_player	*tmp;

  tmp = server->players;
  i = 0;
  while (tmp && !tmp->notify && ++i && (tmp = tmp->next));
  if (!tmp || !tmp->notify)
    return (0);
  send_msg(server, player->fd, "pdi %u\n", i);
  return (1);
}

int		event_pnw(t_server *server, t_player *player)
{
  int 		i;
  t_player	*tmp;

  tmp = server->players;
  i = 0;
  while (tmp && !tmp->notify && ++i && (tmp = tmp->next));
  if (!tmp || !tmp->notify)
    return (0);
  fprintf(stderr, "%d %d\n", tmp->fd, tmp->teams.id);
  send_msg(server, player->fd, "pnw %u %u %u %u %u %s\n",
	   i, tmp->x, tmp->y, tmp->dir, tmp->lvl,
	   server->param.n[tmp->teams.id]);
  return (1);
}

int		event_ppo(t_server *server, t_player *player)
{
  int 		i;
  t_player	*tmp;

  tmp = server->players;
  i = 0;
  while (tmp && !tmp->notify && ++i && (tmp = tmp->next));
  if (!tmp || !tmp->notify)
    return (0);
  player->param[0] = i;
  cmd_mon_ppo(server, player);
  player->param[0] = -1;
  return (1);
}

void 		notify(t_server *server, char *fn)
{
  int 		i;
  t_player	*player;

  i = -1;
  player = server->players;
  while (player && player->teams.id != GRAPHIC && (player = player->next));
  while (events[++i].cmd && strcmp(fn, events[i].cmd));
  if (player && player->fd != -1
      && player->teams.id == GRAPHIC && events[i].fn)
    events[i].fn(server, player);
}
