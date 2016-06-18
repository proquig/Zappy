//
// Created by cloquet on 15/06/16.
//

#include "server.h"
#include "player.h"
#include "map.h"
#include "mon_cmd.h"

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
	// {"-", NULL, &die},
};


int 	set_team(t_server *server, t_player *player)
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
  return (player->team != -1);
}

int	analyse_commande(t_server *server, t_player *player)
{
  // TODO: free
  int	i;

  i = -1;
  if (!server->tab || !server->tab[0])
    return (0);
  if (player->team == -1)
	if (!set_team(server, player))
    {
      dprintf(player->fd, "ko\n");
	  return (-1);
    }
  	else
	  return (0);
  if (player->team != GRAPHIC)
  	{
	  while (commande[++i].cmd)
	  	if (!strcmp(commande[i].cmd, server->tab[0]))
		  commande[i].f(server, player);
  	}
  else
	exec_graphic_cmd(server, player);

  return (0);
}