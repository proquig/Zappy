//
// Created by cloquet on 15/06/16.
//

#include "server.h"
#include "player.h"
#include "map.h"
#include "mon_cmd.h"

t_command commande[] = {
        {"avance",      &avance,      7}, //temps = 7/t
        {"droite",      &right,       7},
        {"gauche",      &gauche,      7},
        {"voir",        &voir,        7},
        {"inventaire",  &inventaire,  1}, // 1/t
        {"prend",       &prend,       7},// 7/t
        {"pose",        &pose,        7},
        {"expulse",     &expulse,     7},
        {"broadcast",   &broadcast,   7},
        {"incantation", &incantation, 300}, // 300/t
        {"fork",        &forker,      42}, // 42/t
        {"connect_nbr", &connect_nbr, 0}, //0
        {NULL, NULL,                  0},
};

int 	set_team(t_server *server, t_player *player)
{
  int	i;

  i = -1;
    //PLAYERUPDATE
  while (server->param.n[++i] && player->teams.id == -1)
    if (strcmp(server->param.n[i], player->tab[0]) == 0 &&
    size_player(server->players, i) < get_team_max(server->players, i, server->param))
      {
          player->teams.id = i;
          player->teams.max = server->param.c;
          send_msg(server, player->fd, "%i\n", server->param.c - size_player(server->players, i));
          send_msg(server, player->fd,"%i %i\n",server->param.x, server->param.y);
      }
//  printf("%s\n", player->tab[0]);
  // TODO: clean that shit
  if (player->teams.id == -1 && strcmp("GRAPHIC", player->tab[0]) == 0)
    {
      player->teams.id = GRAPHIC;
	  cmd_mon_msz(server, player);
	  cmd_mon_sgt(server, player);
	  cmd_mon_mct(server, player);
	  cmd_mon_tna(server, player);
    }

    return (player->teams.id != -1);
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
    {
        printf("Client essaye de se co en temps que %s\n", player->tab[0]);
        if (!set_team(server, player)) {
            send_msg(server, player->fd, "ko\n");
            return (-1);
        }
        else {
            printf("Client Connecte\n");
            return (0);
        }
    }
    if (player->teams.id != GRAPHIC) {
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
		  send_msg(server, player->fd,"ko\n");
    }
    else
        exec_graphic_cmd(server, player);
    return (0);
}
