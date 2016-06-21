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
    typedef void (IA::*fct)(Client *client);
    typedef std::map<std::string, fct> action;

    action  map;
  int	_lvl;
  std::string _ressource_parcer;
  int	_ressources;
  int	_linemate;
  int	_deraumere;
  int	_sibur;
  int	_mendiane;
  int	_phiras;
  int	_thystame;
  int	_food;
  std::string _team_name;

 public:
  IA();
  ~IA();

  void  welcome(Client *client);
  void  coord(Client *client);
  void  dead(Client *client);
  void  ok(Client *client);
  void  first(Client *client);
  void  get_command(Client *client);
  void  parse_command(Client *client, int n);
  void  team(Client *client);
  void  what_i_do(Client *client, std::vector<std::string> tab, int x);
  void	avance(Client *client);
  void	droite(Client *client);
  void	gauche(Client *client);
  void	voir(Client *client);
  void	inventaire(Client *client);
  void	prendre(Client *client, std::string obj);
  void	pose(Client *client, std::string obj);
  void	expulse(Client *client);
  void	broad(Client *client);
  void	incant(Client *client);
  void	inventaire();
  void	prendre();
  void	pose();
  void	expulse();
  void	broad();
  void	incant();

  /* Getter Setter */
  int  get_lvl() const;
  void set_lvl(int _lvl);
  std::string get_ressource_parcer() const;
  void set_ressource_parcer(std::string _ressource_parcer);
  int  get_ressources() const;
  void set_ressources(int _ressources);
  int  get_linemate() const;
  void set_linemate(int _linemate);
  int  get_deraumere() const;
  void set_deraumere(int _deraumere);
  int  get_sibur() const;
  void set_sibur(int _sibur);
  int  get_mendiane() const;
  void set_mendiane(int _mendiane);
  int  get_phiras() const;
  void set_phiras(int _phiras);
  int  get_thystame() const;
  void set_thystame(int _thystame);
  int  get_food() const;
  void set_food(int _food);
  std::string get_team_name() const;
  void set_team_name(std::string &_team_name);
  /* Getter Setter */
};

#endif
