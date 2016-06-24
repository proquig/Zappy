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
  this->set_lvl(1);
  this->set_ressources({1, 0, 0, 0, 0, 0, 0});
}

IA::~IA()
{ }

void	IA::init_team(Client *client)
{
  std::string command1;

  std::cout << "MESSAGE SEND : " << client->get_team_name();
  send(client->get_sock(), client->get_team_name().c_str(), strlen(client->get_team_name().c_str()), 0);
  client->mygetline(this->_command);
  this->print(this->getCommand(), 2);
  client->mygetline(command1);
  this->print(command1, 3);
  this->voir(client);
}

void	IA::dead(Client *client)
{
  (void)client;
  this->print("mort", 4);
  exit (42);
}

bool	IA::full_or_not(Client *client, std::vector<std::vector<int>> tab_lvl)
{
  int	n;
  int	x;
  (void)client;

  n = 1;
  if (this->get_lvl() == 1)
    x = 0;
  else
    x = this->get_lvl() - 1;
  while (n != 6)
    {
      if (tab_lvl[x][n] != 0)
	  {
	    if (this->get_ressources()[n] >= tab_lvl[x][n])
          n++;
	    else
          return (false);
	  }
      else
        n++;
    }
  std::cout << "il y a " << this->get_ressources()[0] << " joueurs sur ma case\n";
  return (this->get_ressources()[0] == tab_lvl[x][0]);
}

void	IA::put_all(Client *client, std::vector<std::vector<int>> tab_lvl)
{
  int	x;
  int	i;

  i = 1;
  if (this->get_lvl() == 1)
    x = 0;
  else
    x = this->get_lvl() - 1;
  while (this->get_ressources()[i] != (this->get_ressources()[i] - tab_lvl[x][i]))
    {
      pose(client, i);
      client->mygetline(this->_command);
      this->print(this->getCommand(), 5);
      if (this->getCommand() == "mort\n")
        this->dead(client);
      i++;
    }
}

void    IA::incant_or_not(Client *client)
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

  if (full_or_not(client, tab_lvl))
  {
    this->put_all(client, tab_lvl);
    this->incant(client);
  }
  else
    this->random_number(client, 2);
}

void     IA::random_number(Client *client, int n)
{
  int x;

  x = (rand() % n) + 1;
  if (this->get_voir().size() >= 3)
  {
    if (this->get_voir()[2].length() >= 1)
      this->avance(client);
    else if (x == 2)
      this->avance(client);
    else
      this->gauche(client);
  }
  else if (x == 2)
    this->avance(client);
  else
    this->gauche(client);
}

void    IA::what_i_do(Client *client, std::vector<std::string> tab)
{
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
      client->mygetline(this->_command);
      if (this->getCommand() == "mort\n")
        dead(client);
      this->print(this->getCommand(), 6);
      this->set_command("");
      i++;
    }
  this->incant_or_not(client);
}

void    IA::parse_command(Client *client)
{
  std::stringstream         stream(client->getCommand());
  std::string               tok;
  std::string               tok1;
  std::vector<std::string>  tab;
  std::vector<std::string>  tab1;
  unsigned int                       i;
  int                       x;

  x = 0;
  i = 0;
  while (std::getline(stream, tok, ','))
    tab.push_back(tok);
  this->set_voir(tab);
  this->set_ressource_parcer(tab[0]);
  std::stringstream         stream1(this->get_ressource_parcer());
  while (std::getline(stream1, tok1, ' '))
    tab1.push_back(tok1);
  while (i != tab1.size())
  {
    if (tab1[i] == "joueur")
      x++;
    i++;
  }
  std::cout << "il y  a " << x << " joueurs sur ma case\n";
  if (tab1.size() != 2)
    this->what_i_do(client, tab1);
  else
    this->random_number(client, 2);
}

void	IA::voir(Client *client)
{

  std::cout << "Message send\t:\tvoir\r\n";
  send(client->get_sock(), "voir\n", strlen("voir\n"), 0);
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
  this->set_table_res({"joueur", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"});
  int i;

  i  = -1;
  while (++i != 6)
  {
    if (obj == this->get_table_res()[i])
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
      put = "pose " + this->get_table_res()[n] + "\r\n";
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

void IA::set_ressource_parcer(std::string _ressource_parcer)
{
  this->_ressource_parcer = _ressource_parcer;
}

void IA::set_command(std::string command)
{
  this->_command = command;
}

void	IA::set_lvl(int _lvl)
{
  IA::_lvl = _lvl;
}

void	IA::set_ressources(std::vector<int> _ressources)
{
  this->_ressources = _ressources;
}

void    IA::set_table_res(std::vector<std::string> table_res)
{
  this->_table_res = table_res;
}

void    IA::set_voir(std::vector<std::string> tab)
{
  this->_tab_voir = tab;
}

int	IA::get_lvl() const
{
  return _lvl;
}

std::string IA::getCommand() const
{
  return _command;
}

std::string IA::get_ressource_parcer() const
{
  return this->_ressource_parcer;
}

std::vector<int>	IA::get_ressources() const
{
  return _ressources;
}

std::vector<std::string> IA::get_table_res() const
{
  return this->_table_res;
}

std::vector<std::string>  IA::get_voir() const
{
  return this->_tab_voir;
}