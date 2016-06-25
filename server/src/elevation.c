//
// Created by cloque_b on 24/06/16.
//

#include <server.h>

int     players_on_square(t_player *root, unsigned int x,
                          unsigned int y, int lvl)
{
    t_player * tmp;
    int         i;

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

int     up_players(t_server *server, t_player *t)
{
    t_player * tmp;
    int         i;

    tmp = server->players;
    i = 0;
    while (tmp)
    {
        printf("root: x%i - y%i [x%i - y%i]\n", tmp->x, tmp->y, t->x, t->y);
        if (tmp->x == t->x && tmp->y == t->y && tmp->lvl == t->lvl)
        {
            tmp->lvl++;
            send_msg(server, tmp->fd,"niveau actuel : %u\n", tmp->lvl);
        }
        tmp = tmp->next;
    }
    return (i);
}

int     tell_to_players(t_server *server, t_player *t)
{
    t_player * tmp;
    int         i;

    tmp = server->players;
    i = 0;
    while (tmp)
    {
        if (tmp->x == t->x && tmp->y == t->y && tmp->lvl == t->lvl) {
            send_msg(server, t->fd, "elevation en cours\n");
        }
        tmp = tmp->next;
    }
  return (i);
}

int     tell_ko_players(t_server *server, t_player *player)
{
    t_player *tmp;
    int         i;

    tmp = server->players;
    i = 0;
    while (tmp)
    {
        if (tmp->x == player->x && tmp->y == player->y
			&& tmp->lvl == player->lvl)
            send_msg(server, player->fd,"ko\n");
        tmp = tmp->next;
    }
    return (i);
}

int     incantation_is_possible(t_server *server, t_player *player)
{
    t_incantation inc[] = {
            {1, {{0, 1, 0, 0, 0, 0, 0}}},
            {2, {{0, 1, 1, 1, 0, 0, 0}}},
            {2, {{0, 2, 0, 1, 0, 2, 0}}},
            {4, {{0, 1, 1, 2, 0, 1, 0}}},
            {4, {{0, 1, 2, 1, 3, 0, 0}}},
            {6, {{0, 1, 2, 3, 0, 1, 0}}},
            {6, {{0, 2, 2, 2, 2, 2, 1}}},
    };
    int         i;

    i = 1;
    if (inc[player->lvl - 1].nb_player !=
            (players_on_square(server->players,
                          player->x, player->y, player->lvl)))
    {
        send_msg(server, player->fd, "ko\n");
        return (0);
    }
    while (i < 7 && server->map[player->y][player->x].res.res[i] == inc[player->lvl -1].res.res[i])
        i++;
    if (i != 7)
        tell_ko_players(server, player);
    return (i == 7);
}

void    incantation(t_server *server, t_player *player)
{
    if (!incantation_is_possible(server, player))
        return;
    else
        up_players(server, player);
}

