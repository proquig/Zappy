/*
** events_player_res.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 11:30:02 2016 Guillaume PROQUIN
** Last update Sun Jun 26 11:30:11 2016 Guillaume PROQUIN
*/

#include "mon_cmd.h"

int 		event_pdr(t_server *server, t_player *player)
{
  int 		i;
  int 		j;
  t_player	*tmp;

  tmp = server->players;
  i = 0;
  j = -1;
  while (tmp && !tmp->notify && ++i && (tmp = tmp->next));
  while (tmp && tmp->notify && !player->res.notify[++j]);
  if (!tmp || !tmp->notify || !player->res.notify[j])
    return (0);
  send_msg(server, player->fd, "pdr %u %u\n", i, j);
  player->param[0] = i;
  cmd_mon_pin(server, player);
  player->param[0] = tmp->x;
  player->param[1] = tmp->y;
  cmd_mon_bct(server, player);
  player->param[0] = -1;
  player->param[1] = -1;
  return (1);
}

int		event_pgt(t_server *server, t_player *player)
{
  int 		i;
  int 		j;
  t_player	*tmp;

  tmp = server->players;
  i = 0;
  j = -1;
  while (tmp && !tmp->notify && ++i && (tmp = tmp->next));
  while (tmp && tmp->notify && !player->res.notify[++j]);
  if (!tmp || !tmp->notify || !player->res.notify[j])
    return (0);
  send_msg(server, player->fd, "pgt %u %u\n", i, j);
  player->param[0] = i;
  cmd_mon_pin(server, player);
  player->param[0] = tmp->x;
  player->param[1] = tmp->y;
  cmd_mon_bct(server, player);
  player->param[0] = -1;
  player->param[1] = -1;
  return (1);
}
