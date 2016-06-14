//
// Created by cloquet on 13/06/16.
//

#include "server.h"

void		set_port(char *pString, t_param *param)
{
  if (pString == NULL || atoi(pString) <= 0)
    error("Port number is incorrect.");
  param->p = atoi(pString);
}

void		set_width(char *pString, t_param *param)
{
  if (pString == NULL || atoi(pString) <= 0)
    error("Width number is incorrect.");
  param->x = atoi(pString);
}

void		set_height(char *pString, t_param *param)
{
  if (pString == NULL || atoi(pString) <= 0)
    error("Height number is incorrect.");
  param->y = atoi(pString);
}

void		set_max_client(char *pString, t_param *param)
{
  if (pString == NULL || atoi(pString) <= 0)
    error("Max clients number is incorrect.");
  param->c = atoi(pString);
}

void		set_delay(char *pString, t_param *param)
{
  if (pString == NULL || atoi(pString) <= 0)
    error("Max clients number is incorrect.");
  param->t = atoi(pString);
}


void		set_team(char **pString, t_param *param)
{
  (void)pString;
  (void)param;
}

void		set_param(char **pString, t_param *param)
{
  int 		j;
  int 		i;
  t_option 	option[] = {
	  {"-p", &set_port},
	  {"-x", &set_width},
	  {"-y", &set_height},
	  {"-c", &set_max_client},
	  {"-t", &set_delay},
	  {NULL, NULL}
  };

  j = -1;
  while (pString[++j])
    {
      i = -1;
      while (option[++i].options)
	{
	  if (strcmp(option[i].options, pString[j]) == 0)
	      option[i].f(pString[j + 1], param);
	  if (strcmp("-n", pString[j]) == 0)
	    set_team(pString, param);
	}
    }
  printf("Port:%i\nMaxclient:%i\nTime:%i\nX:%i\nY:%i\n", param->p, param->c, param->t, param->x, param->y);
}