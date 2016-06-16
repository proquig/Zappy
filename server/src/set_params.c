/*
** set_params.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server/src
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Tue Jun 14 09:51:06 2016 Guillaume PROQUIN
** Last update Wed Jun 15 17:47:56 2016 Guillaume PROQUIN
*/

#include "server.h"

void		init_params(t_param *params)
{
  params->p = 0;
  params->x = 0;
  params->y = 0;
  params->c = 6;
  params->t = 100;
  params->n = NULL;
}

int		set_int_param(const char **args, void *param)
{
  int		i;

  i = -1;
  while (args[++i] && args[i][0] != '-');
  if (i != 1 || (args[0] && (!is_number(args[0]) || atoi(args[0]) <= 0)))
    return (0);
  *((int*)param) = atoi(args[0]);
  return (1);
}

int		set_char_param(const char **args, void *param)
{
  int		i;
  int		j;

  i = -1;
  while (args[++i] && args[i][0] != '-');
  if (!i || !(*((char***)param) = malloc((i + 1) * sizeof(char *))))
    return (0);
  j = -1;
  while (++j < i)
    (*(char***)param)[j] = strdup(args[j]);
  (*(char***)param)[j] = NULL;
  return (1);
}

int		set_params(const char **args, t_param *params)
{
  int		i;
  int		j;
  t_option	option[] = {
    {'p', &params->p, &set_int_param},
    {'x', &params->x, &set_int_param},
    {'y', &params->y, &set_int_param},
    {'c', &params->c, &set_int_param},
    {'t', &params->t, &set_int_param},
    {'n', &params->n, &set_char_param},
    {0, NULL, NULL}
  };

  i = 0;
  while (args[++i] && args[1][0] == '-')
    {
      j = -1;
      while (args[i][0] == '-'
	     && option[++j].arg && option[j].arg != args[i][1]);
      if (args[i][0] == '-' && (args[i][2] || !option[j].f ||
				!(*option[j].f)(&args[i + 1], option[j].param)))
	return (0);
    }
  i = -1;
  while (option[++i].arg && option[i].param);
  return (!option[i].arg);
}
