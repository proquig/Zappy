//
// get_command.cpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Fri Jun 17 14:44:55 2016 jacque_x
// Last update Fri Jun 17 20:11:08 2016 jacque_x
//

#include "Client.hpp"
#include "IA.hpp"

void	get_command(Client client)
{
  std::string	str(client._team_name);
  char          buf[255];
  IA		ia;

  str = str + "\n";
  client._team_name = (char*)str.c_str();
  start_ia(client);
  while (client.mygetline())
    {
      ia.voir(client);
      if (strcmp(buf, "mort\r\n") == 0)
	exit(65);
    }
}

bool	Client::mygetline()
{
  size_t        n;
  char          *command;
  FILE          *stream;

  command = NULL;
  n = 0;
  stream = fdopen(this->_sock, "r");
  getline(&command, &n, stream);
  printf("%s\n", command);
  return (true);
}
