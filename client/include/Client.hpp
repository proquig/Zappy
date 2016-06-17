//
// Client.hpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client/include
//
// Made by jacque_x
// Login   <jacque_x@epitech.net>
//
// Started on  Wed Jun 15 19:02:22 2016 jacque_x
// Last update Fri Jun 17 14:54:33 2016 jacque_x
//

#ifndef _CLIENT_HPP_
#define _CLIENT_HPP_

#include        <stdlib.h>
#include	<ext/stdio_filebuf.h>
#include	<fstream>
#include	<iostream>
#include        <stdio.h>
#include        <memory.h>
#include        <netdb.h>
#include        <zconf.h>
#include        <sys/types.h>
#include        <sys/socket.h>
#include        <netinet/in.h>
#include        <arpa/inet.h>
#include        <unistd.h>

class Client
{
public:
  int		_port;
  int           _sock;
  struct sockaddr_in   _sin;
  Client(int port);
  ~Client();
  void  create_socket();
  void  init_struct();
  void	connect_to_server();
};

void    verif_params(char **av);
void    error(const char *msg);
void	get_command(Client client);

#endif
