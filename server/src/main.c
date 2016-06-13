/*
** main.c for  in /home/cloquet/PSU_2015_zappy/server/src
** 
** Made by Cloquet
** Login   <cloquet@epitech.net>
** 
** Started on  Fri Jun 10 12:17:55 2016 Cloquet
** Last update Fri Jun 10 12:18:16 2016 Cloquet
*/

#include "server.h"

int		main(int ac, char **av)
{
  t_param	param;

  if (ac < 7)
    error("argv");
  set_param(av, &param);
  return (0);
}