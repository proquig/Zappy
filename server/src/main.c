/*
** main.c for  in /home/cloquet/PSU_2015_zappy/server/src
** 
** Made by Cloquet
** Login   <cloquet@epitech.net>
** 
** Started on  Fri Jun 10 12:17:55 2016 Cloquet
** Last update Sun Jun 26 10:17:37 2016 Guillaume PROQUIN
*/

#include <time.h>
#include <signal.h>
#include "server.h"
#include "map.h"

void			init_env(t_fds *fds)
{
  int			i;

  i = -1;
  while (++i < MAX_FD)
  {
    fds->fct_read[i] = NULL;
    fds->fct_write[i] = NULL;
    fds->fd_type[i] = FD_FREE;
  }
}

void			print_param(t_param *param)
{
  int			i;

  i = -1;
  printf("Listening on port %i\n"
	 "Configuration : Max(%i) "
	 "WorldX(%i) WorldY(%i) T(%i)\n",
	 param->p, param->c, param->x, param->y, param->t);
  printf("Team :\n");
  while (param->n[++i])
      printf("\tName(%s) Max(%i)\n", param->n[i], param->c);
}

void			zappy(t_server *server)
{
  int 			i;

  i = -1;
  if (init_server(&server->param, &server->fds) == -1)
    error("Server init failed");
  if (server->param.c * tablen(server->param.n) + 1 > MAX_FD)
	server->param.c = 5;
  if (server->param.t > 1000000
	  || server->param.x > 100 || server->param.y > 100)
	error("Wrong parameter");
  print_param(&server->param);
  server->map = create_map(server->param.x, server->param.y);
  while ((unsigned int)++i < (server->param.x * server->param.y * 4))
	put_random_ressource(server->map, server->param.x, server->param.y);
  printf("Generating world...done\n");
  start_server(server);
}

int			main(int ac, const char **av)
{
  t_server		server;
  struct timeval	val;

  srand(gettimeofday(&val, NULL) * time(NULL));
  if (ac < 7)
    error("argv");
  init_params(&server.param);
  init_env(&server.fds);
  if (!set_params(av, &server.param))
    error("Wrong args");
  signal(SIGPIPE, SIG_IGN);
  signal(SIGINT, handle_signal);
  server_is_running(1);
  zappy(&server);
  return (0);
}
