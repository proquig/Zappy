//
// get_command.cpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Fri Jun 17 14:44:55 2016 jacque_x
// Last update Sat Jun 18 13:05:49 2016 jacque_x
//

#include "IA.hpp"

void    IA::get_command(Client *client)
{
  std::string command;
  action map;

  map.insert(std::make_pair(std::string("BIENVENUE\n"), &IA::team));
  map.insert(std::make_pair(std::string("12 23\n"), &IA::coord));
  map.insert(std::make_pair(std::string("mort\n"), &IA::dead));
  map.insert(std::make_pair(std::string("ok\n"), &IA::ok));
  while (client->mygetline(command))
  {
    std::cout << "Server send : " << command << std::endl;
    if (command.length() == 2)
      std::cout << " ";
    else if (map.count(command))
    {
      for (action::iterator it = map.begin(); it != map.end(); ++it)
      {
        if (it->first == command)
          (this->*it->second)(client);
      }
    }
    else
      this->parse_command(client, 0);
    command = "";
  }
}
