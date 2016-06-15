/*
** utils.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server/src
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Tue Jun 14 09:50:48 2016 Guillaume PROQUIN
** Last update Tue Jun 14 09:50:52 2016 Guillaume PROQUIN
*/

#include "server.h"

void		error(const char *msg)
{
  fprintf(stderr, "\033[31m%s\033[0m\n", msg);
  exit(0);
}

int		is_number(const char *str)
{
  return (!str[0] || (str[0] >= '0' && str[0] <= '9' && is_number(&str[1])));
}
