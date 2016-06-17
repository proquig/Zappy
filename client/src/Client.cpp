//
// Client.cpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client/src
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Wed Jun 15 22:27:43 2016 jacque_x
// Last update Fri Jun 17 17:19:11 2016 jacque_x
//

#include "Client.hpp"

Client::Client(int port, char *team_name)
{
  this->_port = port;
  this->_team_name = team_name;
}

Client::~Client()
{

}

void	Client::create_socket()
{
  this->_sock = socket(AF_INET, SOCK_STREAM, 0);
}

void	Client::init_struct()
{
  this->_sin.sin_addr.s_addr = inet_addr("127.0.0.1");
  this->_sin.sin_family = AF_INET;
  this->_sin.sin_port = htons(this->_port);
}

void	Client::connect_to_server()
{
  if (connect(this->_sock, (struct sockaddr*)&(this->_sin), sizeof(this->_sin)) != -1)
    printf("Connexion à %s sur le port %d\n", inet_ntoa(this->_sin.sin_addr), htons(this->_sin.sin_port));
  else
    {
      perror("connect");
      printf("Impossible de se connecter\n");
    }
}
