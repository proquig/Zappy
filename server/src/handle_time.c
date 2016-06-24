//
// Created by proqui_g on 6/22/16.
//

#include "server.h"

int 		time_is_lower(struct timeval *time1, struct timeval *time2)
{
  return (time1->tv_sec < time2->tv_sec ||
		  (time1->tv_sec == time2->tv_sec && time1->tv_usec < time2->tv_usec));
}

int			action_is_waiting(struct timeval *time)
{
  struct timeval	now;

  gettimeofday(&now, NULL);
  return (time_is_lower(&now, time));
}

void 		set_action_time(struct timeval *time, int value, int frequency)
{
  int 		new_utime;

  if (!time->tv_sec && !time->tv_usec)
	gettimeofday(time, NULL);
  new_utime = (int)(time->tv_usec
			  + ((double)value / frequency * FREQUENCY));
  time->tv_sec += new_utime / FREQUENCY;
  time->tv_usec = new_utime % FREQUENCY;
}
