/*
** mon_cmd.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 11:01:25 2016 Guillaume PROQUIN
** Last update Sun Jun 26 11:59:05 2016 Guillaume PROQUIN
*/

#include "mon_cmd.h"

const t_cmd	mon_cmds[] = {
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

int		cmd_mon_sgt(t_server *server, t_player *player)
{
  send_msg(server, player->fd, "sgt %u\n", server->param.t);
  return (1);
}

int		cmd_mon_sst(t_server *server, t_player *player)
{
  if (!is_number(player->tab[1]) || atoi(player->tab[1]) <= 0
      || atoi(player->tab[1]) > FREQUENCY)
    return (0);
  server->param.t = atoi(player->tab[1]);
  send_msg(server, player->fd, "sgt %u\n", server->param.t);
  return (1);
}

void		exec_graphic_cmd(t_server *server, t_player *player)
{
  int		i;
  int		nb_params;

  i = -1;
  nb_params = -1;
  while (player->tab[++nb_params]);
  while (mon_cmds[++i].cmd
	 && strcmp(mon_cmds[i].cmd, player->tab[0]));
  if (!mon_cmds[i].cmd || nb_params != (mon_cmds[i].nb_params + 1)
      || !mon_cmds[i].fn(server, player))
    send_msg(server, player->fd, "%s\n", mon_cmds[i].cmd ? "sbp" : "suc");
}

void		cmd_mon_welcome(t_server *server, t_player *player)
{
  t_player	*tmp;

  tmp = server->players;
  player->teams.id = GRAPHIC;
  cmd_mon_msz(server, player);
  cmd_mon_sgt(server, player);
  cmd_mon_mct(server, player);
  cmd_mon_tna(server, player);
  while (tmp)
    {
      if (tmp->fd != -1 && tmp->teams.id != -1
		  && tmp->teams.id != GRAPHIC)
	{
	  tmp->notify = 1;
	  notify(server, "pnw");
	  tmp->notify = 0;
	}
      tmp = tmp->next;
    }
}
