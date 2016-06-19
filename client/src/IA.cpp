//
// IA.cpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client/src
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Fri Jun 17 17:28:31 2016 jacque_x
// Last update Sat Jun 18 11:28:11 2016 jacque_x
//

#include "IA.hpp"

IA::IA()
{ }

IA::~IA()
{ }

void	IA::team(Client *client)
{
    std::cout << client->get_team_name() << std::endl;
    send(client->get_sock(), client->get_team_name().c_str(), strlen(client->get_team_name().c_str()), 0);
}

void    IA::dead(Client *client)
{
    exit (42);
}

void    IA::ok(Client *client)
{
    this->voir(client);
}

void    IA::coord(Client *client)
{
    this->voir(client);
}

void    IA::what_i_do(Client *client, std::vector<std::string> tab, int x)
{
  int i;
  std::srand((unsigned)time(0));
  int n;

  n = (rand() % 3) + 1;
  i = 0;
  if (x == 1)
      this->parse_command(client, 1);
  else if (x == 2)
  {
      if (tab.size() >= 3)
          this->prendre(client, tab[2]);
      else if (this->_linemate >= 1 && tab.size() == 2)
          this->incant(client);
      else
      {
          if (n == 1)
              this->gauche(client);
          else if (n == 2)
              this->droite(client);
          else
              this->avance(client);
      }
  }
  else
  {
      if (tab[2].find("linemate") != std::string::npos)
          i++;
      if (i != 0)
          this->avance(client);
      else
      {
          if (n == 1)
              this->gauche(client);
          else
              this->droite(client);
      }
  }
}

void    IA::parse_command(Client *client, int n)
{
  std::stringstream         stream(client->getCommand());
  std::string               tok;
  std::vector<std::string>  tab;

  if (n == 0)
  {
    while (std::getline(stream, tok, ','))
      tab.push_back(tok);
    this->set_ressource_parcer(tab[0]);
    this->what_i_do(client, tab, 1);
  }
  else
  {
    std::stringstream         stream1(this->get_ressource_parcer());

    while (std::getline(stream1, tok, ' '))
        tab.push_back(tok);
    this->what_i_do(client, tab, 2);
  }
}

void	IA::voir(Client *client)
{
  std::cout << "Message send : voir\r\n";
  send(client->get_sock(), "voir\n", strlen("voir\n"), 0);
}

void     IA::inventaire(Client *client)
{
  std::cout << "Message send : inventaire\r\n";
  send(client->get_sock(), "inventaire\r\n", strlen("inventaire\r\n"), 0);
}

void    IA::avance(Client *client)
{
  std::cout << "Message send : avance\r\n";
  send(client->get_sock(), "avance\r\n", strlen("avance\r\n"), 0);
}

void    IA::droite(Client *client)
{
  std::cout << "Message send : droite\r\n";
  send(client->get_sock(), "droite\r\n", strlen("droite\r\n"), 0);
}

void    IA::gauche(Client *client)
{
  std::cout << "Message send : gauche\r\n";
  send(client->get_sock(), "gauche\r\n", strlen("gauche\r\n"), 0);
}

void    IA::prendre(Client *client, std::string obj)
{
  std::string take;

  if (obj == "linemate")
      this->_linemate++;
  if (obj == "deraumere")
      this->_deraumere++;
  if (obj == "sibur")
      this->_sibur++;
  if (obj == "mendiane")
      this->_mendiane++;
  if (obj == "phiras")
      this->_phiras++;
  if (obj == "thystame")
      this->_thystame++;
  take = "prend ";
  take = take + obj + "\r\n";
  std::cout << "Message send : "<< take;
  send(client->get_sock(), take.c_str(), take.length(), 0);
}

void    IA::pose(Client *client)
{
  std::cout << "Message send : pose\r\n";
  send(client->get_sock(), "pose\r\n", strlen("pose\r\n"), 0);
}

void    IA::expulse(Client *client)
{
  std::cout << "Message send : expulse\r\n";
  send(client->get_sock(), "expulse\r\n", strlen("expulse\r\n"), 0);
}

void    IA::broad(Client *client)
{
  std::cout << "Message send : broadcast\r\n";
  send(client->get_sock(), "broadcast\r\n", strlen("broadcast\r\n"), 0);
}

void    IA::incant(Client *client)
{
  std::cout << "Message send : incantation\r\n";
  send(client->get_sock(), "incantation\r\n", strlen("incant\r\n"), 0);
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

int	IA::get_lvl() const
{
  return _lvl;
}

void	IA::set_lvl(int _lvl)
{
  IA::_lvl = _lvl;
}

int	IA::get_ressources() const
{
  return _ressources;
}

void	IA::set_ressources(int _ressources)
{
  IA::_ressources = _ressources;
}

int	IA::get_linemate() const
{
  return _linemate;
}

void	IA::set_linemate(int _linemate)
{
  IA::_linemate = _linemate;
}

int 	IA::get_deraumere() const
{
  return _deraumere;
}

void 	IA::set_deraumere(int _deraumere)
{
  IA::_deraumere = _deraumere;
}

int 	IA::get_sibur() const
{
  return _sibur;
}

void 	IA::set_sibur(int _sibur)
{
  IA::_sibur = _sibur;
}

int 	IA::get_mendiane() const
{
  return _mendiane;
}

void 	IA::set_mendiane(int _mendiane)
{
  IA::_mendiane = _mendiane;
}

int 	IA::get_phiras() const
{
  return _phiras;
}

void 	IA::set_phiras(int _phiras)
{
  IA::_phiras = _phiras;
}

int 	IA::get_thystame() const
{
  return _thystame;
}

void 	IA::set_thystame(int _thystame)
{
  IA::_thystame = _thystame;
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