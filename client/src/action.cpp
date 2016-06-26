//
// action.cpp for  in 
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Sun Jun 26 11:22:57 2016 jacque_x
// Last update Sun Jun 26 15:21:34 2016 jacque_x
//

#include "IA.hpp"

void    IA::voir(Client *client)
{
  std::string tmp("voir\n");

  std::cout << "Message send\t:\tvoir\n";
  send(client->get_sock(), tmp.c_str(), tmp.size(), 0);
}

void    IA::avance(Client *client)
{
  std::string tmp("avance\n");

  std::cout << "Message send\t:\tavance\n";
  send(client->get_sock(), tmp.c_str(), tmp.size(), 0);
}

void    IA::droite(Client *client)
{
  std::string tmp("droite\n");

  std::cout << "Message send\t:\tdroite\n";
  send(client->get_sock(), tmp.c_str(), tmp.size(), 0);
}

void    IA::gauche(Client *client)
{
  std::string tmp("gauche\n");

  std::cout << "Message send\t:\tgauche\n";
  send(client->get_sock(), tmp.c_str(), tmp.size(), 0);
}

void    IA::prendre(Client *client, std::string obj)
{
  std::string   take;
  int           i;

  i  = -1;
  this->set_table_res({"joueur", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"});
  while (++i != 6)
    {
      if (obj == this->get_table_res()[i])
        this->_ressources[i]++;
    }
  take = "prend " + obj + "\n";
  if (obj != "cours\n" && obj != "joueur" && obj != "elevation")
    {
      std::cout << "Message send\t:\t" << take;
      send(client->get_sock(), take.c_str(), take.length(), 0);
    }
}

void    IA::pose(Client *client, int i)
{
  std::string   put;
  int           n;

  n = 0;
  while (++n != 6)
    {
      if (n == i)
        {
          this->_ressources[n]--;
          put = "pose " + this->get_table_res()[n] + "\n";
        }
    }
  std::cout << "Message send\t:\t" << put;
  send(client->get_sock(), put.c_str(), put.length(), 0);
}

void    IA::expulse(Client *client)
{
  std::string tmp("expulse\n");

  std::cout << "Message send\t:\texpulse\n";
  send(client->get_sock(), tmp.c_str(), tmp.size(), 0);
}

void    IA::broad(Client *client)
{
  std::string tmp("broadcast\n");

  std::cout << "Message send\t:\tbroadcast\n";
  send(client->get_sock(), tmp.c_str(), tmp.size(), 0);
}

void    IA::fork(Client *client)
{
  std::string tmp("fork\n");

  std::cout << "Message send\t:\tfork\n";
  send(client->get_sock(), tmp.c_str(), tmp.size(), 0);
}

int    IA::incant(Client *client)
{
  std::string tmp("incantation\n");

  std::cout << "Message send\t:\tincantation\n";
  send(client->get_sock(), tmp.c_str(), tmp.size(), 0);
  return (0);
}
