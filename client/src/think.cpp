//
// think.cpp for  in 
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Sun Jun 26 11:28:19 2016 jacque_x
// Last update Sun Jun 26 16:49:53 2016 jacque_x
//

#include "IA.hpp"

void    IA::init_team(Client *client)
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

void    IA::dead(Client *client)
{
  (void)client;
  this->print("mort", 4);
  exit (42);
}

bool    IA::full_or_not(Client *client, std::vector<std::vector<int>> tab_lvl)
{
  int   n;
  int   x;
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
  return (this->get_ressources()[0] == tab_lvl[x][0]);
}

void    IA::put_all(Client *client, std::vector<std::vector<int>> tab_lvl)
{
  int   x;
  int   i;

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
      std::cout << "JE SUIS LEVEL " << this->_lvl << std::endl;
      this->incant(client);
      client->mygetline(this->_command);
      print(this->_command, 21);
      while (this->_command[0] != 'n' && this->_command[0] != 'k')
	{
	  set_command("");
	  client->mygetline(this->_command);
	}
      print(this->_command, 22);
      this->_lvl++;
      this->fork(client);
    }
  else
    this->random_number(client, 2);
}

void    IA::what_i_do(Client *client, std::vector<std::string> tab)
{
  unsigned int  i;
  unsigned int  x;

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
  std::stringstream             stream(client->getCommand());
  std::string                   tok;
  std::string                   tok1;
  std::vector<std::string>      tab;
  std::vector<std::string>      tab1;
  unsigned int                  i;
  int                           x;

  x = 0;
  i = 0;
  this->_str_voir = client->getCommand();
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
  this->_ressources[0] = x;
  if (tab1.size() != 2)
    this->what_i_do(client, tab1);
  else
    this->random_number(client, 2);
}

void    IA::random_number(Client *client, int n)
{
  int		x;
  std::string	command;
  bool		i;
  int		a;
  int		j;

  this->_up = false;
  j = 0;
  a = 0;
  i = true;
  x = (rand() % n) + 1;
  while (this->_str_voir[a])
    {
      if (j == 3)
	if (this->_str_voir[a] != ',')
	  this->_up = true;
      if (this->_str_voir[a] == '{' || this->_str_voir[a] == ',')
	j++;
      a++;
    }
  if (this->_up == true)
    {
      i = false;
      this->avance(client);
    }
   if (i == true)
    {
      if (x == 1)
        {
          this->gauche(client);
          client->mygetline(command);
          print(command, 11);
          this->avance(client);
        }
      else
        {
          this->droite(client);
	  client->mygetline(command);
	  print(command, 11);
          this->avance(client);
        }
    }
}
