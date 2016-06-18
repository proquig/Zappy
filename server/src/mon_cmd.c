//
// Created by proqui_g on 6/18/16.
//

#include "mon_cmd.h"

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
  dprintf(player->fd, "msz %d %d\n", server->param.x, server->param.y);
  return (1);
}

int 	cmd_mon_bct(t_server *server, t_player *player)
{
  return (1);
}

int 	cmd_mon_mct(t_server *server, t_player *player)
{
  return (1);
}

int 	cmd_mon_tna(t_server *server, t_player *player)
{
  return (1);
}

int 	cmd_mon_ppo(t_server *server, t_player *player)
{
  return (1);
}

int 	cmd_mon_plv(t_server *server, t_player *player)
{
  return (1);
}

int 	cmd_mon_pin(t_server *server, t_player *player)
{
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
  while (server->tab[++nb_params]);;
  while (mon_cmds[++i].cmd
		 && strcmp(mon_cmds[i].cmd, server->tab[0]));
  printf("%s %d %d\n", mon_cmds[i].cmd, (mon_cmds[i].nb_params + 1), nb_params);
  if (!mon_cmds[i].cmd || nb_params != (mon_cmds[i].nb_params + 1)
	  || !mon_cmds[i].fn(server, player))
	dprintf(player->fd, "%s\n", mon_cmds[i].cmd ? "sbp" : "suc");
}