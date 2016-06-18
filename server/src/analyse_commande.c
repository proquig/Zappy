//
// Created by cloquet on 15/06/16.
//

#include "server.h"
#include "player.h"
#include "map.h"

t_command	commande[] = {
	{"avance", NULL, &avance},
	{"droite", NULL, &right},
	{"gauche", NULL, &gauche},
	{"voir", NULL, &voir},
	{"inventaire", NULL, &inventaire},
	{"prend", NULL, &prend},
	{"pose", NULL, &pose},
	{"expulse", NULL, &expulse},
	{"broadcast", "texte", &broadcast},
	{"incantation", NULL, &incantation},
	{"fork", NULL, &forker},
	{"connect_nbr", NULL, &connect_nbr},
	{"-", NULL, &die},
};


void 	set_team(t_server *server, t_player *player)
{
  int i;

  i = -1;
  while (server->param.n[++i] && player->team == -1)
    if (strcmp(server->param.n[i], server->tab[0]) == 0)
      {
	player->team = i;
	dprintf(player->fd, "%i\n%i %i\n", player->fd, player->x, player->y);
      }
  printf("%s\n", server->tab[0]);
  if (player->team == -1 && strcmp("GRAPHIC", server->tab[0]) == 0)
    {
      player->team = GRAPHIC;
      print_map_contents(server->map, player->fd);
    }
}

int	analyse_commande(t_server *server, t_player *player)
{
  int	i;

  i = -1;
  if (!server->tab || !server->tab[0])
    return (0);
  set_team(server, player);
  if (player->team == -1)
    {
      dprintf(player->fd, "ko\n");
     return (-1);
    }
  while (commande[++i].cmd)
      if (strcmp(commande[i].cmd, server->tab[0]) == 0)
	commande[i].f(server, player);
  return (0);
}