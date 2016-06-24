//
// get_command.cpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Fri Jun 17 14:44:55 2016 jacque_x
// Last update Tue Jun 21 14:06:37 2016 jacque_x
//

#include "IA.hpp"

void    IA::get_command(Client *client)
{
  action map;

  map.insert(std::make_pair(std::string("BIENVENUE\n"), &IA::init_team));
  map.insert(std::make_pair(std::string("mort\n"), &IA::dead));
  while (client->mygetline(this->_command))
    {
      std::cout << "\E[31;1mRECEIVED_1 : " << this->getCommand() << "\E[m";
      if (map.count(this->getCommand()))
        {
            (this->*map.at(this->getCommand()))(client);
            this->setCommand("");
        }
      else if (this->getCommand() == "ok\n" || this->getCommand() == "ko\n")
        {
            this->setCommand("");
            this->voir(client);
        }
      else
        {
            this->parse_command(client);
            this->setCommand("");
        }
      this->setCommand("");
    }
}
