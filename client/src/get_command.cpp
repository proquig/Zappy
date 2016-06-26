//
// get_command.cpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Fri Jun 17 14:44:55 2016 jacque_x
// Last update Sun Jun 26 11:15:13 2016 jacque_x
//

#include "IA.hpp"

void    IA::get_command(Client *client)
{
  action map;

  map.insert(std::make_pair(std::string("BIENVENUE\n"), &IA::init_team));
  map.insert(std::make_pair(std::string("mort\n"), &IA::dead));
  while (client->mygetline(this->_command))
    {
      this->print(this->getCommand(), 1);
      if (map.count(this->getCommand()))
        {
	  (this->*map.at(this->getCommand()))(client);
	  this->set_command("");
        }
      else if (this->getCommand() == "ok\n" || this->getCommand() == "ko\n")
        {
	  this->set_command("");
	  this->voir(client);
        }
      else
        {
	  this->parse_command(client);
	  this->set_command("");
        }
      this->set_command("");
    }
}
