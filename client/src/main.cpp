//
// main.cpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client/src
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Wed Jun 15 22:22:39 2016 jacque_x
// Last update Fri Jun 17 14:51:55 2016 jacque_x
//

#include "Client.hpp"

int	main(int ac, char **av)
{
  if (ac != 4)
    error("Bad number of params");
  verif_params(av);
  Client client(atoi(av[2]));

  client.create_socket();
  client.init_struct();
  client.connect_to_server();
  get_command(client);
  return (0);
}
