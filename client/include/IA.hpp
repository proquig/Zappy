//
// IA.hpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client/include
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Fri Jun 17 17:33:54 2016 jacque_x
// Last update Fri Jun 17 18:17:20 2016 jacque_x
//

#ifndef _IA_HPP_
#define _IA_HPP_

#include "Client.hpp"

class IA
{
public:
  int	_lvl;
  int	_ressources;
  int	_linemate;
  int	_deraumere;
  int	_sibur;
  int	_mendiane;
  int	_phiras;
  int	_thystame;
  int	_food;
  char	*_team_name;
  //
  IA();
  ~IA();
  void	avance();
  void	droite();
  void	gauche();
  void	voir(Client client);
  void	inventaire();
  void	prendre();
  void	pose();
  void	expulse();
  void	broad();
  void	incant();
};

#endif
