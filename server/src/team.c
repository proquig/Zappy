/*
** team.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 11:39:54 2016 Guillaume PROQUIN
** Last update Sun Jun 26 12:52:50 2016 Guillaume PROQUIN
*/

#include "server.h"
#include "mon_cmd.h"

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

int			set_team(t_server *server, t_player *player)
{
  int			i;

  i = -1;
  while (server->param.n[++i] && player->teams.id == -1)
    if (!strcmp(server->param.n[i], player->tab[0])
	&& size_player(server->players, i)
	< get_team_max(server->players, i, server->param))
      {
	player->teams.id = i;
	cmd_welcome(server, player);
      }
  if (player->teams.id == -1 && !strcmp("GRAPHIC", player->tab[0]))
    cmd_mon_welcome(server, player);
  if (player->teams.id == -1)
    send_msg(server, player->fd, "ko\n");
  return (player->teams.id != -1 ? 0 : -1);
}

int			get_team_max(t_player *root, int id, t_param param)
{
  t_player		*tmp;
  int			max;

  tmp = root;
  max = param.c;
  while (tmp)
    {
      if (tmp->teams.id == id)
	max = tmp->teams.max > param.c ? tmp->teams.max : param.c;
      tmp = tmp->next;
    }
  return (max);
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
