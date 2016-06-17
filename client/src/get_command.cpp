//
// get_command.cpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Fri Jun 17 14:44:55 2016 jacque_x
// Last update Fri Jun 17 16:22:57 2016 jacque_x
//

#include "Client.hpp"

void	get_command(Client client)
{
  size_t        n;
  char          buf[255];
  char          *command;
  FILE          *stream;

  command = NULL;
  n = 0;
  stream = fdopen(0, "r");
  while (1)
    {
      bzero(&buf[0], 255);
      if (recv(client._sock, buf, 255, 0) > 0)
        printf("%s", buf);
      if (strcmp(buf, "mort") == 0)
	exit(65);
      getline(&command, &n, stream);
      send(client._sock, command, strlen(command), 0);
    }
}

