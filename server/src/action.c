//
// Created by cloque_b on 21/06/16.
//

#include	"server.h"

void 		init_action(t_action *action)
{
  action->f = NULL;
  action->cmd = NULL;
  action->exec = 0;
  action->time.tv_sec = 0;
  action->time.tv_usec = 0;
}

void        init_actions(t_action actions[10])
{
    int     i;

    i = -1;
    while (++i < NB_ACTIONS)
	  init_action(&actions[i]);
}

t_action        *find_free_action(t_action actions[10])
{
    int         i = -1;
    while (++i < NB_ACTIONS && actions[i].f);
    return (i == NB_ACTIONS ? NULL : &actions[i]);
}

t_action        *get_current_action(t_action actions[10])
{
  int           i;
  i = -1;

  while (++i < 10 && !actions[i].exec);
  return (i == 10 ? NULL : &actions[i]);
}

void            set_action(t_server *server, t_player *player, int time,
                           void (*fn)(t_server *, t_player *))
{
  int               i;
  t_action        *action;
  struct timeval  *old_time;

  old_time = NULL;
  i = -1;
  while (++i < 10)
    if (!old_time || time_is_lower(old_time, &player->actions[i].time))
      old_time = &player->actions[i].time;
  if ((action = find_free_action(player->actions)))
    {
      if (old_time)
      {
        action->time.tv_sec = old_time->tv_sec;
        action->time.tv_usec = old_time->tv_usec;
      }
      action->cmd = get_cmds(player->cmd, " \t\r\n");
      action->f = fn;
      set_action_time(&action->time, time, server->param.t);
    }
}
