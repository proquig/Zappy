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
 private:
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

 public:
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

  /* Getter Setter */
  int get_lvl() const;
  void set_lvl(int _lvl);
  int get_ressources() const;
  void set_ressources(int _ressources);
  int get_linemate() const;
  void set_linemate(int _linemate);
  int get_deraumere() const;
  void set_deraumere(int _deraumere);
  int get_sibur() const;
  void set_sibur(int _sibur);
  int get_mendiane() const;
  void set_mendiane(int _mendiane);
  int get_phiras() const;
  void set_phiras(int _phiras);
  int get_thystame() const;
  void set_thystame(int _thystame);
  int get_food() const;
  void set_food(int _food);
  char *get_team_name() const;
  void set_team_name(char *_team_name);
  /* Getter Setter */
};

#endif
