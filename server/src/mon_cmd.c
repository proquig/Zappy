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

int 	cmd_mon_msz(t_server *server, t_player *player)
{
  send_msg(server, player->fd, "msz %u %u\n", server->param.x, server->param.y);
  return (1);
}

int 	cmd_mon_bct(t_server *server, t_player *player)
{
  unsigned int 	x;
  unsigned int 	y;

  x = strtoul(player->tab[1], NULL, 10);
  y = strtoul(player->tab[2], NULL, 10);
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

  i = -1;
  tmp = server->players;
  while (++i < atoi(player->tab[1]) && (tmp = tmp->next));
  if (!tmp || tmp->teams.id == GRAPHIC || i != atoi(player->tab[1]))
	return (0);
  send_msg(server, player->fd, "ppo %u %u %u %u\n", i,
		  player->x, player->y, player->dir);
  return (1);
}

int 	cmd_mon_plv(t_server *server, t_player *player)
{
  t_player	*tmp;
  int 	i;

  i = -1;
  tmp = server->players;
  while (++i < atoi(player->tab[1]) && (tmp = tmp->next));
  if (!tmp || tmp->teams.id == GRAPHIC || tmp->fd == -1 || i != atoi(player->tab[1]))
	return (0);
  send_msg(server, player->fd, "plv %u %u\n", i, player->lvl);
  return (1);
}

int 	cmd_mon_pin(t_server *server, t_player *player)
{
  t_player	*tmp;
  int 	i;

  i = -1;
  tmp = server->players;
  while (++i < atoi(player->tab[1]) && (tmp = tmp->next));
  if (!tmp || tmp->teams.id == GRAPHIC || i != atoi(player->tab[1]))
	return (0);
  send_msg(server, player->fd, "plv %u %u %u", i, player->x, player->y);
  i = -1;
  while (++i < RES_SIZE)
	send_msg(server, player->fd, " %d", player->res.res[i]);
  send_msg(server, player->fd, "\n");
  return (1);
}

int 	cmd_mon_sgt(t_server *server, t_player *player)
{
  return (1);
}

int 	cmd_mon_sst(t_server *server, t_player *player)
{
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