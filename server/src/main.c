/*
** main.c for  in /home/cloquet/PSU_2015_zappy/server/src
** 
** Made by Cloquet
** Login   <cloquet@epitech.net>
** 
** Started on  Fri Jun 10 12:17:55 2016 Cloquet
** Last update Tue Jun 14 13:27:49 2016 Guillaume PROQUIN
*/

#include "../../common/include/player.h"
#include "server.h"

void        init_env(t_env *env)
{
  int       i;

  i = -1;
  while (++i < MAX_FD)
  {
    env->fct_read[i] = NULL;
    env->fct_write[i] = NULL;
    env->fd_type[i] = FD_FREE;
  }
}

void		print_param(t_param param)
{
  int 		i;

  i = -1;
  printf("\033[32;1mListening on port %i\n"
		 "Configuration : Max(%i) "
		 "WorldX(%i) WorldY(%i) T(%i)\033[0m\n",
	 param.p, param.c, param.x, param.y, param.t);
  printf("\033[32;1mTeam :\033[0m\n");
  while (param.n[++i])
      printf("\033[32;1m\tName(%s) Max(%i)\033[0m\n", param.n[i], param.c);
}

void 		zappy(t_param *param, t_env *env)
{
  t_square  **map;

  if (init_server(param, env) == -1)
    error("Server init failed");
  print_param(*param);
  map = create_map(param->x, param->y);
  start_server(env, param, map);
}

int		main(int ac, const char **av)
{
  t_param	param;
  t_env		env;

  if (ac < 7)
    error("argv");
  init_params(&param);
  init_env(&env);
  if (!set_params(av, &param))
    error("Wrong args");
  zappy(&param, &env);
  return (0);
}
