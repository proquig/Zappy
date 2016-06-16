//
// Created by cloquet on 15/06/16.
//

#include "server.h"

t_command	commande[] = {
	{"avance", NULL, &avance},
	{"droite", NULL, &move_right},
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


void 	set_team(char **tab, t_player *player, t_param *param, t_square ***map)
{
  int i;

  i = -1;
  while (param->n[++i] && player->team == -1)
    if (strcmp(param->n[i], tab[0]) == 0)
      {
	player->team = i;
	dprintf(player->fd, "%i\n%i %i\n", player->fd, player->x, player->y);
      }
  printf("%s\n", tab[0]);
  if (player->team == -1 && strcmp("GRAPHIC", tab[0]) == 0)
    {
      player->team = GRAPHIC;
      print_map_contents(map, player->fd, param->x, param->y);
    }
}

int	analyse_commande(char **tab, t_player *player, t_param *param, t_square ***map)
{
  int	i;

  i = -1;
  set_team(tab, player, param, map);
  if (player->team == -1)
    {
      if (strcmp(commande[i].cmd, tab[0]) == 0)
	commande[i].f();
    }
  return (0);
}