//
// IA.cpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client/src
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Fri Jun 17 17:28:31 2016 jacque_x
// Last update Fri Jun 17 20:57:28 2016 jacque_x
//

#include "IA.hpp"

IA::IA()
{ }

IA::~IA()
{ }

void	start_ia(Client client)
{
  IA	ia;

  std::cout << client.get_team_name() << std::endl;
  send(client.get_sock(), client.get_team_name().c_str(), strlen(client.get_team_name().c_str()), 0);
}

void	IA::voir(Client client)
{
  std::cout << "Message send : voir\n";
  send(client.get_sock(), "voir\n", strlen("voir\n"), 0);
}

/* Getter Setter */

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

char 	*IA::get_team_name() const
{
  return _team_name;
}

void 	IA::set_team_name(char *_team_name)
{
  IA::_team_name = _team_name;
}