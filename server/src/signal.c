/*
** signal.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 11:10:42 2016 Guillaume PROQUIN
** Last update Sun Jun 26 11:54:27 2016 Guillaume PROQUIN
*/

#include "server.h"

int			server_is_running(int check)
{
  static int		is_running = 1;

  if (!check)
    is_running = 0;
  return (is_running);
}

void			handle_signal(int signal)
{
  (void)signal;
  server_is_running(0);
}
