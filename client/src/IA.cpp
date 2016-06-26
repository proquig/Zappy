//
// IA.cpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client/src
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Fri Jun 17 17:28:31 2016 jacque_x
// Last update Sun Jun 26 11:32:11 2016 jacque_x
//

#include "IA.hpp"

IA::IA()
{ 
  this->set_lvl(1);
  this->set_ressources({1, 0, 0, 0, 0, 0, 0});
}

IA::~IA()
{ }

void	IA::set_ressource_parcer(std::string _ressource_parcer)
{
  this->_ressource_parcer = _ressource_parcer;
}

void	IA::set_command(std::string command)
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

std::string	IA::getCommand() const
{
  return _command;
}

std::string	IA::get_ressource_parcer() const
{
  return this->_ressource_parcer;
}

std::vector<int>	IA::get_ressources() const
{
  return _ressources;
}

std::vector<std::string>	IA::get_table_res() const
{
  return this->_table_res;
}

std::vector<std::string>	IA::get_voir() const
{
  return this->_tab_voir;
}
