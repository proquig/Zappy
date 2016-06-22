//
// Created by cloque_b on 21/06/16.
//

#include	"server.h"

t_action	*init_action(void (*fonction)(t_server *server, t_player *player),
			     int time)
{
    t_action	*action;

    if (!(action = malloc(sizeof(t_action))))
        return (NULL);
    action->f = fonction;
    action->next = NULL;
    action->time = time;
    return (action);
}

t_action	*add_action(t_action *list, t_action *new)
{
    t_action	*tmp;

    if (!list && !new)
        return (NULL);
    if (!list)
        return (new);
    tmp = list;
    while (tmp->next && (tmp = tmp->next));
    tmp->next = new;
    return (list);
}
