//
// Created by proqui_g on 6/18/16.
//

#include "mon_cmd.h"
#include "map.h"

const t_cmd mon_cmds[] = {
		{"msz", 0, &cmd_mon_msz},
		{"bct", 2, &cmd_mon_bct},
		{"mct", 0, &cmd_mon_mct},
		{"tna", 0, &cmd_mon_tna},
		{"ppo", 1, &cmd_mon_ppo},
		{"plv", 1, &cmd_mon_plv},
		{"pin", 1, &cmd_mon_pin},
		{"sgt", 0, &cmd_mon_sgt},
		{"sst", 1, &cmd_mon_sst},
		{NULL, 0, NULL}
};

const t_cmd events[] = {
		{"pdi", 0, &event_pdi},
		{"pnw", 0, &event_pnw},
		{"ppo", 0, &event_ppo},
		{"pdr", 0, &event_pdr},
		{"pgt", 0, &event_pgt},
		{NULL, 0, NULL}
};

int 	cmd_mon_msz(t_server *server, t_player *player)
{
  send_msg(server, player->fd, "msz %u %u\n",
		   server->param.x, server->param.y);
  return (1);
}

int 	cmd_mon_bct(t_server *server, t_player *player)
{
  unsigned int 	x;
  unsigned int 	y;

  x = player->param[0] != -1
	  ? player->param[0] : strtoul(player->tab[1], NULL, 10);
  y = player->param[1] != -1
	  ? player->param[1] : strtoul(player->tab[2], NULL, 10);
  if (x >= server->param.x
	  || y >= server->param.y)
	return (0);
  print_square_contents(server, player, &server->map[y][x]);
  return (1);
}

int 	cmd_mon_mct(t_server *server, t_player *player)
{
  print_map_contents(server, player);
  return (1);
}

int 	cmd_mon_tna(t_server *server, t_player *player)
{
  int 	i;

  i = -1;
  while (server->param.n[++i])
	send_msg(server, player->fd, "tna %s\n", server->param.n[i]);
  return (1);
}

int 	cmd_mon_ppo(t_server *server, t_player *player)
{
  t_player	*tmp;
  int 	i;
  int 	nb;

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

int 	cmd_mon_plv(t_server *server, t_player *player)
{
  t_player	*tmp;
  int 	i;
  int 	nb;

  i = -1;
  nb = (player->param[0] != -1) ? player->param[0] : atoi(player->tab[1]);
  tmp = server->players;
  while (++i < nb && (tmp = tmp->next));
  if (!tmp || tmp->teams.id == GRAPHIC || tmp->fd == -1 || i != nb)
	return (0);
  send_msg(server, player->fd, "plv %u %u\n", i, tmp->lvl);
  return (1);
}

int 	cmd_mon_pin(t_server *server, t_player *player)
{
  t_player	*tmp;
  int 	i;
  int 	nb;

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

int 	cmd_mon_sgt(t_server *server, t_player *player)
{
  send_msg(server, player->fd, "sgt %u\n", server->param.t);
  return (1);
}

int 	cmd_mon_sst(t_server *server, t_player *player)
{
  if (!is_number(player->tab[1]) || atoi(player->tab[1]) <= 0
		  || atoi(player->tab[1]) > FREQUENCY)
	return (0);
  server->param.t = atoi(player->tab[1]);
  send_msg(server, player->fd, "sgt %u\n", server->param.t);
  return (1);
}

void	exec_graphic_cmd(t_server *server, t_player *player)
{
  int	i;
  int	nb_params;

  i = -1;
  nb_params = -1;
  while (player->tab[++nb_params]);
  while (mon_cmds[++i].cmd
		 && strcmp(mon_cmds[i].cmd, player->tab[0]));
  if (!mon_cmds[i].cmd || nb_params != (mon_cmds[i].nb_params + 1)
	  || !mon_cmds[i].fn(server, player))
	send_msg(server, player->fd, "%s\n", mon_cmds[i].cmd ? "sbp" : "suc");
}

int			event_pdi(t_server *server, t_player *player)
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

int			event_pnw(t_server *server, t_player *player)
{
  int 		i;
  t_player	*tmp;

  tmp = server->players;
  i = 0;
  while (tmp && !tmp->notify && ++i && (tmp = tmp->next));
  if (!tmp || !tmp->notify)
	return (0);
  send_msg(server, player->fd, "pnw %u %u %u %u %u %s\n",
		   i, tmp->x, tmp->y, tmp->dir, tmp->lvl,
		   server->param.n[tmp->teams.id]);
  return (1);
}

int			event_ppo(t_server *server, t_player *player)
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

int			event_pgt(t_server *server, t_player *player)
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
  else
	printf("YOU LOSE\n");
  if (player)
	printf(">>>= %d %d\n", player->fd, player->teams.id);
}