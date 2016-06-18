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
  std::string	command;
  std::string	str(client.get_team_name());
  IA		ia;

  str = str + "\n";
  client.set_team_name(str);
  while (client.mygetline(command))
    {
      if (command == "BIENVENUE\n")
	  start_ia(client);
      command = "";
      //ia.voir(client);
    }
}


