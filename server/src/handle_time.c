//
// Created by proqui_g on 6/22/16.
//

#include "server.h"

int			action_is_waiting(struct timeval *time)
{
  struct timeval	now;

  gettimeofday(&now, NULL);
  return (now.tv_usec < time->tv_sec ||
		  (now.tv_usec == time->tv_sec && now.tv_usec < time->tv_usec));
}

void 		set_action_time(struct timeval *time, int value, int frequency)
{
  int 		new_utime;
  gettimeofday(time, NULL);

  new_utime = time->tv_usec + (value / frequency) * 1000000;
  time->tv_sec += new_utime / 1000000;
  time->tv_usec = new_utime % 1000000;
}
