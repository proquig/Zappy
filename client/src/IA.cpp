//
// IA.cpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client/src
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Fri Jun 17 17:28:31 2016 jacque_x
// Last update Thu Jun 23 23:50:02 2016 jacque_x
//

#include "IA.hpp"

IA::IA()
{ 
  this->_lvl = 1;
  this->_ressources = {1, 0, 0, 0, 0, 0, 0};
}

IA::~IA()
{ }

void	IA::init_team(Client *client)
{
  std::string command1;

  std::cout << "MESSAGE SEND : " << client->get_team_name();
  send(client->get_sock(), client->get_team_name().c_str(), strlen(client->get_team_name().c_str()), 0);
  client->mygetline(this->_command);
  std::cout << "\E[31;1mRECEIVED : " << this->getCommand() << "\E[m";
  client->mygetline(command1);
  std::cout << "\E[31;1mRECEIVED : " << command1 << "\E[m";
  this->voir(client);
}

void	IA::dead(Client *client)
{
  (void)client;
  std::cout << "\E[31;1mRECEIVED : mort\E[m\n";
  exit (42);
}

bool	IA::full_or_not(Client *client, std::vector<std::vector<int>> tab_lvl)
{
  int	n;
  int	x;
  (void)client;

  n = 1;
  if (this->_lvl == 1)
    x = 0;
  else
    x = this->_lvl - 1;
  while (n != 6)
    {
      if (tab_lvl[x][n] != 0)
	  {
	    if (this->_ressources[n] >= tab_lvl[x][n])
          n++;
	    else
          return (false);
	  }
      else
        n++;
    }
  if (this->_ressources[0] == tab_lvl[x][0])
    return (true);
  return (false);
}

void	IA::put_all(Client *client, std::vector<std::vector<int>> tab_lvl)
{
  int	x;
  int	i;

  i = 1;
  if (this->_lvl == 1)
    x = 0;
  else
    x = this->_lvl - 1;
  while (this->_ressources[i] != (this->_ressources[i] - tab_lvl[x][i]))
    {
      pose(client, i);
      client->mygetline(this->_command);
      std::cout << "\E[31;1mRECEIVED : " << this->getCommand() << "\E[m";
      if (this->getCommand() == "mort\n")
        this->dead(client);
      i++;
    }
}

void    IA::coord(Client *client)
{
  std::srand((unsigned)time(0));
  std::vector<std::vector<int>> tab_lvl = {
          {1, 1, 0, 0, 0, 0, 0},
          {2, 1, 1, 1, 0, 0, 0},
          {2, 2, 0, 1, 0, 2, 0},
          {4, 1, 1, 2, 0, 1, 0},
          {4, 1, 2, 1, 3, 0, 0},
          {6, 1, 2, 3, 0, 1, 0},
          {6, 2, 2, 2, 2, 2, 1}
  };

  if (full_or_not(client, tab_lvl) == true)
  {
    this->put_all(client, tab_lvl);
    this->incant(client);
  }
  else
    this->random_number(client, 3);
}

void     IA::random_number(Client *client, int n)
{
  int x;

  x = (rand() % n) + 1;
  if (x == 1)
    this->avance(client);
  else if (x == 2)
    this->droite(client);
  else
    this->gauche(client);
}

void    IA::what_i_do(Client *client, std::vector<std::string> tab)
{
  std::string command;
  unsigned int	i;
  unsigned int	x;

  i = 0;
  x = 0;
  while (i != tab.size())
  {
    if (tab[i] == "joueur" || tab[i] == "{")
      x++;
    if (tab[i] == "elevation")
      x = 2;
    i++;
  }
  i = x;
  while (i != (tab.size()))
    {
      this->prendre(client, tab[i]);
      client->mygetline(command);
      if (command == "mort\n")
        dead(client);
      std::cout << "\E[31;1mRECEIVED_4 : " << command << "\E[m";
      command = "";
      i++;
    }
  this->coord(client);
}

void    IA::parse_command(Client *client)
{
  std::stringstream         stream(client->getCommand());
  std::string               tok;
  std::string               tok1;
  std::vector<std::string>  tab;
  std::vector<std::string>  tab1;

  while (std::getline(stream, tok, ','))
    tab.push_back(tok);
  this->set_ressource_parcer(tab[0]);
  std::stringstream         stream1(this->get_ressource_parcer());
  while (std::getline(stream1, tok1, ' '))
    tab1.push_back(tok1);
  if (tab1.size() != 2)
    this->what_i_do(client, tab1);
  else
    this->random_number(client, 3);
}

void	IA::voir(Client *client)
{
  std::cout << "Message send\t:\tvoir\r\n";
  send(client->get_sock(), "voir\n", strlen("voir\n"), 0);
}

void     IA::inventaire(Client *client)
{
  std::cout << "Message send\t:\tinventaire\r\n";
  send(client->get_sock(), "inventaire\r\n", strlen("inventaire\r\n"), 0);
}

void    IA::avance(Client *client)
{
  std::cout << "Message send\t:\tavance\r\n";
  send(client->get_sock(), "avance\r\n", strlen("avance\r\n"), 0);
}

void    IA::droite(Client *client)
{
  std::cout << "Message send\t:\tdroite\r\n";
  send(client->get_sock(), "droite\r\n", strlen("droite\r\n"), 0);
}

void    IA::gauche(Client *client)
{
  std::cout << "Message send\t:\tgauche\r\n";
  send(client->get_sock(), "gauche\r\n", strlen("gauche\r\n"), 0);
}

void    IA::prendre(Client *client, std::string obj)
{
  std::string take;
  this->table_res = {"joueur", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"};
  int i;

  i  = -1;
  while (++i != 6)
  {
    if (obj == this->table_res[i])
      this->_ressources[i]++;
  }
  take = "prend " + obj + "\r\n";
  if (obj != "cours\n" && obj != "joueur" && obj != "elevation")
  {
    std::cout << "Message send\t:\t" << take;
    send(client->get_sock(), take.c_str(), take.length(), 0);
  }
  else
    this->_lvl++;
}

void    IA::pose(Client *client, int i)
{
  std::string put;
  int n;

  n = 0;
  while (++n != 6)
  {
    if (n == i)
    {
      this->_ressources[n]--;
      put = "pose " + this->table_res[n] + "\r\n";
    }
  }
  std::cout << "Message send\t:\t" << put;
  send(client->get_sock(), put.c_str(), put.length(), 0);
}

void    IA::expulse(Client *client)
{
  std::cout << "Message send\t:\texpulse\r\n";
  send(client->get_sock(), "expulse\r\n", strlen("expulse\r\n"), 0);
}

void    IA::broad(Client *client)
{
  std::cout << "Message send\t:\tbroadcast\r\n";
  send(client->get_sock(), "broadcast\r\n", strlen("broadcast\r\n"), 0);
}

int    IA::incant(Client *client)
{

  std::cout << "Message send\t:\tincantation\r\n";
  send(client->get_sock(), "incantation\r\n", strlen("incantation\r\n"), 0);
  return (0);
}

/* Getter Setter */

std::string IA::get_ressource_parcer() const
{
    return this->_ressource_parcer;
}

void IA::set_ressource_parcer(std::string _ressource_parcer)
{
    this->_ressource_parcer = _ressource_parcer;
}

void IA::setCommand(std::string command)
{
  this->_command = command;
}

std::string IA::getCommand() const
{
  return _command;
}

int	IA::get_lvl() const
{
  return _lvl;
}

void	IA::set_lvl(int _lvl)
{
  IA::_lvl = _lvl;
}

std::vector<int>	IA::get_ressources() const
{
  return _ressources;
}

void	IA::set_ressources(std::vector<int> _ressources)
{
  this->_ressources = _ressources;
}

int 	IA::get_food() const
{
  return _food;
}

void 	IA::set_food(int _food)
{
  IA::_food = _food;
}

std::string IA::get_team_name() const
{
  return _team_name;
}

void 	IA::set_team_name(std::string &_team_name)
{
  IA::_team_name = _team_name;
}
