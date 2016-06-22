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

int set_team(t_server *server, t_player *player) {
    int i;

    i = -1;
    while (server->param.n[++i] && player->team == -1)
        if (strcmp(server->param.n[i], server->tab[0]) == 0 &&
                size_player(server->players, i) < server->param.c) {
            player->team = i;
            dprintf(player->fd, "%i\n", server->param.c - size_player(server->players, i));
            dprintf(player->fd, "%i %i\n", server->param.x, server->param.y);
        }
    if (player->team == -1 && strcmp("GRAPHIC", server->tab[0]) == 0) {
        player->team = GRAPHIC;
        print_map_contents(server->map, player->fd);
    }
    return (player->team != -1);
}
//  check erreur team tees done
//  action test décharge list
//  print tout en fin done

int analyse_commande(t_server *server, t_player *player) {
    int i;

    i = -1;
    if (!server->tab || !server->tab[0])
        return (0);
    if (player->team == -1) {
        if (!set_team(server, player)) {
            dprintf(player->fd, "ko\n");
            return (-1);
        }
    }
    else
        return (0);
    if (player->team != GRAPHIC) {
        while (commande[++i].cmd) {
            if (!strcmp(commande[i].cmd, server->tab[0])) {
                player->actions = add_action(player->actions, init_action(commande[i].f, commande[i].time / server->param.t));
            }
        }
    }
    else
        exec_graphic_cmd(server, player);
    free_tab(server->tab);
    return (0);
}
