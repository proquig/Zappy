//
// IA.cpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client/src
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Fri Jun 17 17:28:31 2016 jacque_x
// Last update Fri Jun 17 20:57:28 2016 jacque_x
//

#include "IA.hpp"

IA::IA()
{

}

IA::~IA()
{

}

void	start_ia(Client client)
{
  IA	ia;

  printf(client._team_name);
  send(client._sock, client._team_name, strlen(client._team_name), 0);
}

void	IA::voir(Client client)
{
  printf("voir\r\n");
  send(client._sock, "voir\r\n", strlen("voir\r\n"), 0);
}
