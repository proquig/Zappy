/*
** elevation.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 09:59:23 2016 Guillaume PROQUIN
** Last update Sun Jun 26 12:35:10 2016 Guillaume PROQUIN
*/

#include "server.h"
#include "player.h"

int		players_on_square(t_player *root, unsigned int x,
				  unsigned int y, int lvl)
{
  t_player	*tmp;
  int		i;

  tmp = root;
  i = 0;
  while (tmp)
    {
      if (tmp->x == x && tmp->y == y && tmp->lvl == lvl)
	i++;
      tmp = tmp->next;
    }
  return (i);
}

int		 up_players(t_server *server, t_player *t)
{
  t_player	*tmp;
  int		i;

  tmp = server->players;
  i = 0;
  while (tmp)
    {
      if (tmp->x == t->x && tmp->y == t->y && tmp->lvl == t->lvl)
	{
	  tmp->lvl++;
	  send_msg(server, tmp->fd, "niveau actuel : %u\n", tmp->lvl);
	}
      tmp = tmp->next;
    }
  return (i);
}

int		incantation_is_possible(t_server *server, t_player *player)
{
  t_incantation	inc[] = {
    {1, {0, 1, 0, 0, 0, 0, 0}},
    {2, {0, 1, 1, 1, 0, 0, 0}},
    {2, {0, 2, 0, 1, 0, 2, 0}},
    {4, {0, 1, 1, 2, 0, 1, 0}},
    {4, {0, 1, 2, 1, 3, 0, 0}},
    {6, {0, 1, 2, 3, 0, 1, 0}},
    {6, {0, 2, 2, 2, 2, 2, 1}},
  };
  int		i;

  i = 1;
  if (inc[player->lvl - 1].nb_player !=
      (players_on_square(server->players, player->x, player->y, player->lvl)))
    {
      send_msg(server, player->fd, "ko\n");
      return (0);
    }
  while (i < 7 && server->map[player->y][player->x].res.res[i]
	 == inc[player->lvl -1].res[i])
    i++;
  if (i != 7)
    tell_ko_players(server, player);
  return (i == 7);
}

int		check_incantation(t_server *server, t_player *player)
{
  if (!incantation_is_possible(server, player))
    {
      tell_ko_players(server, player);
      return (0);
    }
  tell_to_players(server, player);
  set_action(server, player, commande[9].time, commande[9].f);
  return (1);
}

void		incantation(t_server *server, t_player *player)
{
  if (incantation_is_possible(server, player))
    up_players(server, player);
}
