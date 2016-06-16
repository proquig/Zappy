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

int	analyse_commande(char **tab, t_player *player)
{
  int	i;

  i = -1;
  if (player->team == 0)
    {
      dprintf(player->fd,"ko\r\n");
      return (-1);
    }
  while (commande[++i].cmd)
      if (strcmp(commande[i].cmd, tab[0]) == 0)
	commande[i].f();
  return (0);
}