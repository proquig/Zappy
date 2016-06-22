//
// Created by cloque_b on 21/06/16.
//

#include	"server.h"

void 		init_action(t_action *action)
{
  action->f = NULL;
  action->time.tv_sec = 0;
  action->time.tv_usec = 0;
}

void        init_actions(t_action actions[10])
{
    int     i;

    i = -1;
    while (++i < 10)
	  init_action(&actions[i]);
}

t_action        *find_free_action(t_action actions[10])
{
    int         i = -1;
    while (++i < 10 && actions[i].f);
    return (i == 10 ? NULL : &actions[i]);
}

void            set_action(t_server *server, t_action actions[10], int time,
                       void (*fn)(t_server *, t_player *))
{
    t_action    *action;

    if ((action = find_free_action(actions)))
    {
        action->f = fn;
        set_action_time(&action->time, time, server->param.t);
    }
}
