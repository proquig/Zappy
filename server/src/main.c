/*
** main.c for  in /home/cloquet/PSU_2015_zappy/server/src
** 
** Made by Cloquet
** Login   <cloquet@epitech.net>
** 
** Started on  Fri Jun 10 12:17:55 2016 Cloquet
** Last update Tue Jun 14 13:27:49 2016 Guillaume PROQUIN
*/

#include <time.h>
#include "server.h"
#include "map.h"

void        init_env(t_fds *fds)
{
  int       i;

  i = -1;
  while (++i < MAX_FD)
  {
    fds->fct_read[i] = NULL;
    fds->fct_write[i] = NULL;
    fds->fd_type[i] = FD_FREE;
  }
}

void		print_param(t_param *param)
{
  int 		i;

  i = -1;
  printf("\033[32;1mListening on port %i\n"
		 "Configuration : Max(%i) "
		 "WorldX(%i) WorldY(%i) T(%i)\033[0m\n",
	 param->p, param->c, param->x, param->y, param->t);
  printf("\033[32;1mTeam :\033[0m\n");
  while (param->n[++i])
      printf("\033[32;1m\tName(%s) Max(%i)\033[0m\n", param->n[i], param->c);
}

void 		zappy(t_server *server)
{
  int 		x;
  int 		y;

  x = -1;
  if (init_server(&server->param, &server->fds) == -1)
    error("Server init failed");
  print_param(&server->param);
  server->map = create_map(server->param.x, server->param.y);
  while (++x < (int)server->param.x)
    {
      y = -1;
      while (++y < (int)server->param.y)
      {
        put_random_ressource(server->map, server->param.x, server->param.y);
        put_random_ressource(server->map, server->param.x, server->param.y);
        put_random_ressource(server->map, server->param.x, server->param.y);
        put_random_ressource(server->map, server->param.x, server->param.y);
        put_random_ressource(server->map, server->param.x, server->param.y);
        put_random_ressource(server->map, server->param.x, server->param.y);
        put_random_ressource(server->map, server->param.x, server->param.y);
        put_random_ressource(server->map, server->param.x, server->param.y);
        put_random_ressource(server->map, server->param.x, server->param.y);
        put_random_ressource(server->map, server->param.x, server->param.y);
        put_random_ressource(server->map, server->param.x, server->param.y);
      }
    }
  printf("\033[32;1mGenerating world...done\033[0m\n");
  start_server(server);
}

int		main(int ac, const char **av)
{
  t_server  server;

  srand(time(NULL));
  if (ac < 7)
    error("argv");
  init_params(&server.param);
  init_env(&server.fds);
  if (!set_params(av, &server.param))
    error("Wrong args");
  zappy(&server);
  return (0);
}
