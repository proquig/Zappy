/*
** main.c for  in /home/cloquet/PSU_2015_zappy/server/src
** 
** Made by Cloquet
** Login   <cloquet@epitech.net>
** 
** Started on  Fri Jun 10 12:17:55 2016 Cloquet
** Last update Tue Jun 14 13:27:49 2016 Guillaume PROQUIN
*/

#include "player.h"
#include "server.h"

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

int		main(int ac, const char **av)
{
  t_param	param;
  t_env		env;

  if (ac < 7)
    error("argv");
  init_params(&param);
  if (!set_params(av, &param))
    error("Wrong args");
  if (init_server(&param, &env) == -1)
    error("Server init failed");
  print_param(param);
  start_server(&env);
  return (0);
}
