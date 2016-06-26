//
// main.cpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client/src
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Wed Jun 15 22:22:39 2016 jacque_x
// Last update Sun Jun 26 14:31:37 2016 jacque_x
//

#include "IA.hpp"

int	main(int ac, char **av)
{
  std::vector<std::string>	tab;
  unsigned int				i;
  std::string			port;
  std::string			host;
  std::string			name;

  i = 0;
  if (ac != 7)
    error("Usage : -n [team_name] -p [port] -h [host]");
  tab = verif_params(av);
  while (i != tab.size())
    {
      if (strcmp(tab[i].c_str(), "-p") == 0)
	port = tab[i + 1];
      if (strcmp(tab[i].c_str(), "-n") == 0)
	name = tab[i + 1];
      if (strcmp(tab[i].c_str(), "-h") == 0)
	host = tab[i + 1];
      i++;
    }
  std::string teamName(name);
  std::string adress(host);
  
  teamName += "\n";
  Client  client(std::atoi(port.c_str()), teamName, adress);
  IA      ia;
  
  client.create_socket();
  client.init_struct();
  client.connect_to_server();
  ia.get_command(&client);
  return (0);
}
