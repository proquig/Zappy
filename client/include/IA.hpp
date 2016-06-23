//
// IA.hpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client/include
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Fri Jun 17 17:33:54 2016 jacque_x
// Last update Tue Jun 21 18:03:21 2016 jacque_x
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
  int _players;
  int _nbr_client;
  int	_food;
  std::string _command;
  std::string _ressource_parcer;
  std::string _team_name;
  std::vector<int> _ressources;
  std::vector<std::string> table_res;

 public:
  IA();
  ~IA();

  void  welcome(Client *client);
  void  coord(Client *client);
  void  dead(Client *client);
  bool  full_or_not(Client *client, std::vector<std::vector<int>> tab_lvl);
  void	put_all(Client *client, std::vector<std::vector<int>> tab_lvl);
  void  first(Client *client);
  void  get_command(Client *client);
  void  parse_command(Client *client);
  void  init_team(Client *client);
  void  what_i_do(Client *client, std::vector<std::string> tab);
  void  connect_nbr(Client *client);
  void	avance(Client *client);
  void	droite(Client *client);
  void	gauche(Client *client);
  void	voir(Client *client);
  void	inventaire(Client *client);
  void	prendre(Client *client, std::string obj);
  void	pose(Client *client, int i);
  void	expulse(Client *client);
  void	broad(Client *client);
  int	incant(Client *client);
  void	inventaire();
  void	prendre();
  void	pose();
  void	expulse();
  void	broad();
  void	incant();
  void  random_number(Client *client, int n);

  /* Getter Setter */
  int  get_lvl() const;
  void set_lvl(int _lvl);
  std::string getCommand() const;
  void setCommand(std::string command);
  std::string get_ressource_parcer() const;
  void set_ressource_parcer(std::string _ressource_parcer);
  std::vector<int>  get_ressources() const;
  void set_ressources(std::vector<int> _ressources);
  int  get_food() const;
  void set_food(int _food);
  std::string get_team_name() const;
  void set_team_name(std::string &_team_name);
  /* Getter Setter */
};

#endif
