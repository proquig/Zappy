//
// IA.hpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client/include
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Fri Jun 17 17:33:54 2016 jacque_x
// Last update Sun Jun 26 16:15:33 2016 jacque_x
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
  int	                    _lvl;
  int                       _players;
  int                       _nbr_client;
  int	                    _food;
  bool			    _up;
  std::string               _command;
  std::string               _ressource_parcer;
  std::string               _team_name;
  std::string		    _str_voir;
  std::vector<int>          _ressources;
  std::vector<std::string>  _table_res;
  std::vector<std::string>  _tab_voir;

 public:
  IA();
  ~IA();

  void  init_team(Client *client);
  void  dead(Client *client);
  bool  full_or_not(Client *client, std::vector<std::vector<int>> tab_lvl);
  void	put_all(Client *client, std::vector<std::vector<int>> tab_lvl);
  void  incant_or_not(Client *client);
  void  random_number(Client *client, int n);
  void  what_i_do(Client *client, std::vector<std::string> tab);
  void  parse_command(Client *client);
  void	voir(Client *client);
  void	avance(Client *client);
  void	droite(Client *client);
  void	gauche(Client *client);
  void	prendre(Client *client, std::string obj);
  void	pose(Client *client, int i);
  void	expulse(Client *client);
  void	broad(Client *client);
  void  fork(Client *client);
  int	incant(Client *client);
  void  get_command(Client *client);
  void  print(std::string command, int i);

  /* Setter */
  void set_ressource_parcer(std::string _ressource_parcer);
  void set_command(std::string command);
  void set_lvl(int _lvl);
  void set_ressources(std::vector<int> _ressources);
  void set_table_res(std::vector<std::string> table_res);
  void set_voir(std::vector<std::string> tab);
  /* Getter */
  int                       get_lvl() const;
  std::string               getCommand() const;
  std::string               get_ressource_parcer() const;
  std::vector<int>          get_ressources() const;
  std::vector<std::string>  get_table_res() const;
  std::vector<std::string>  get_voir() const;
};

#endif
