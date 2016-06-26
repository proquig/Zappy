/*
** analyse_commande.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 09:55:06 2016 Guillaume PROQUIN
** Last update Sun Jun 26 12:59:22 2016 Guillaume PROQUIN
*/

#include "server.h"
#include "player.h"
#include "map.h"
#include "mon_cmd.h"

t_command	commande[12] = {
  {"avance",		NULL,			&avance,	7},
  {"droite",		NULL,			&right,		7},
  {"gauche",		NULL,			&gauche,	7},
  {"voir",		NULL,			&voir,		7},
  {"inventaire",	NULL,			&inventaire,	1},
  {"prend",		NULL,			&prend,		7},
  {"pose",		NULL,			&pose,		7},
  {"expulse",		NULL,			&expulse,	7},
  {"broadcast",		NULL,			&broadcast,	7},
  {"incantation",	&check_incantation,	&incantation,	300},
  {"fork",		NULL,			&forker,	42},
  {NULL,		NULL,			NULL,		0}
};

void		cmd_welcome(t_server *server, t_player *player)
{
  player->teams.max = server->param.c < player->teams.max ?
    player->teams.max : server->param.c;
  player->notify = 1;
  notify(server, "pnw");
  player->notify = 0;
  send_msg(server, player->fd, "%i\n",
	   server->param.c - size_player(server->players, player->teams.id));
  send_msg(server, player->fd, "%i %i\n", server->param.x, server->param.y);
}

int		is_in_command(char *str)
{
  int		i;

  i = -1;
  while (commande[++i].cmd)
    if (!strcmp(commande[i].cmd, str))
      return (1);
  return (0);
}

int		analyse_commande(t_server *server, t_player *player)
{
  int		i;

  i = -1;
  player->tab = get_cmds(player->cmd, " \t\r\n");
  if (!player->tab || !player->tab[0])
    return (0);
  if (player->teams.id == -1)
    return (set_team(server, player));
  else if (player->teams.id != GRAPHIC)
    {
      while (commande[++i].cmd)
	if (!strcmp(commande[i].cmd, player->tab[0])
	    && (!commande[i].check || commande[i].check(server, player)))
	  set_action(server, player, commande[i].time, commande[i].f);
      if (!is_in_command(player->tab[0]))
	send_msg(server, player->fd, "ko\n");
    }
  else
    exec_graphic_cmd(server, player);
  return (0);
}
