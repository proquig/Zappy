/*
** analyse_commande.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 09:55:06 2016 Guillaume PROQUIN
** Last update Sun Jun 26 12:15:17 2016 Guillaume PROQUIN
*/

#include "server.h"
#include "player.h"
#include "map.h"
#include "mon_cmd.h"

t_command	commande[] = {
        {"avance",	&avance,	7},
        {"droite",	&right,		7},
        {"gauche",	&gauche,	7},
        {"voir",	&voir,		7},
        {"inventaire",	&inventaire,	1},
        {"prend",	&prend,		7},
        {"pose",	&pose,		7},
        {"expulse",	&expulse,	7},
        {"broadcast",	&broadcast,	7},
        {"incantation",	&incantation,	300},
        {"fork",	&forker,	42},
        {NULL,		NULL,		0}
};

void	cmd_welcome(t_server *server, t_player *player)
{
  player->teams.max = server->param.c;
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
  if (!player->tab || !player->tab[0])
    return (0);
  if (player->teams.id == -1)
    if (!set_team(server, player))
      {
	send_msg(server, player->fd, "ko\n");
	return (-1);
      }
  else if (player->teams.id != GRAPHIC) {
    while (commande[++i].cmd)
      {
	if (!strcmp(player->tab[0], "incantation"))
	  {
	    if (incantation_is_possible(server, player) == 1) {
	      tell_to_players(server, player);
	      set_action(server, player, commande[9].time, commande[9].f);
	    }
	    else
	      tell_ko_players(server, player);
	    return 0;
	  }
	else if (!strcmp(commande[i].cmd, player->tab[0]))
	  set_action(server, player, commande[i].time, commande[i].f);
      }
    if (!is_in_command(player->tab[0]))
      send_msg(server, player->fd, "ko\n");
  }
  else
    exec_graphic_cmd(server, player);
  return (0);
}
