/*
** mon_cmd_player.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 11:26:43 2016 Guillaume PROQUIN
** Last update Sun Jun 26 11:28:46 2016 Guillaume PROQUIN
*/

#include "mon_cmd.h"

int		cmd_mon_tna(t_server *server, t_player *player)
{
  int		i;

  i = -1;
  while (server->param.n[++i])
    send_msg(server, player->fd, "tna %s\n", server->param.n[i]);
  return (1);
}

int		cmd_mon_ppo(t_server *server, t_player *player)
{
  t_player	*tmp;
  int		i;
  int		nb;

  i = -1;
  nb = (player->param[0] != -1) ? player->param[0] : atoi(player->tab[1]);
  tmp = server->players;
  while (++i < nb && (tmp = tmp->next));
  if (!tmp || tmp->teams.id == GRAPHIC || tmp->fd == -1 || i != nb)
    return (0);
  send_msg(server, player->fd, "ppo %u %u %u %u\n", i,
	   tmp->x, tmp->y, tmp->dir);
  return (1);
}

int		cmd_mon_plv(t_server *server, t_player *player)
{
  t_player	*tmp;
  int		i;
  int		nb;

  i = -1;
  nb = (player->param[0] != -1) ? player->param[0] : atoi(player->tab[1]);
  tmp = server->players;
  while (++i < nb && (tmp = tmp->next));
  if (!tmp || tmp->teams.id == GRAPHIC || tmp->fd == -1 || i != nb)
    return (0);
  send_msg(server, player->fd, "plv %u %u\n", i, tmp->lvl);
  return (1);
}

int		cmd_mon_pin(t_server *server, t_player *player)
{
  t_player	*tmp;
  int		i;
  int		nb;

  i = -1;
  nb = (player->param[0] != -1) ? player->param[0] : atoi(player->tab[1]);
  tmp = server->players;
  while (++i < nb && (tmp = tmp->next));
  if (!tmp || tmp->teams.id == GRAPHIC || tmp->fd == -1 || i != nb)
    return (0);
  send_msg(server, player->fd, "pin %u %u %u", i, tmp->x, tmp->y);
  i = -1;
  while (++i < RES_SIZE)
    send_msg(server, player->fd, " %d", tmp->res.res[i]);
  send_msg(server, player->fd, "\n");
  return (1);
}
