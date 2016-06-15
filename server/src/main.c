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

int		main(int ac, char **av)
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
  start_server(&env);
  return (0);
}
