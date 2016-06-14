/*
** main.c for  in /home/cloquet/PSU_2015_zappy/server/src
** 
** Made by Cloquet
** Login   <cloquet@epitech.net>
** 
** Started on  Fri Jun 10 12:17:55 2016 Cloquet
** Last update Tue Jun 14 11:32:35 2016 Guillaume PROQUIN
*/

#include "server.h"

int		main(int ac, char **av)
{
  t_param	param;

  if (ac < 7)
    error("argv");
  init_params(&param);
  if (!set_params(av, &param))
    error("Wrong args");
  init_server(&param);
  return (0);
}
