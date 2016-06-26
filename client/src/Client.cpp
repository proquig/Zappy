//
// Client.cpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client/src
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Wed Jun 15 22:27:43 2016 jacque_x
// Last update Sun Jun 26 11:13:47 2016 jacque_x
//

#include <SocketBuf.hpp>
#include "Client.hpp"

Client::Client(int port, std::string &team_name, std::string &addr):
	_port(port),
	_team_name(team_name),
	_address(addr)
{
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
  if (this->_address == "localhost")
    this->_address = "127.0.0.1";
  this->_sin.sin_addr.s_addr = inet_addr(this->_address.c_str());
  this->_sin.sin_family = AF_INET;
  this->_sin.sin_port = htons(static_cast<uint16_t>(this->_port));
}

void	Client::connect_to_server()
{
  if (connect(this->_sock, (struct sockaddr*)&(this->_sin), sizeof(this->_sin)) != -1)
    {
      std::cout << "Connexion à " << inet_ntoa(this->_sin.sin_addr) << " sur le port " << htons(this->_sin.sin_port) << std::endl;
      _socket1.setFdSocket(this->_sock);
    }
  else
    perror("connect");
}

bool	Client::mygetline(std::string& command)
{
  command = _socket1.read();
  setCommand(command);
  return (true);
}

void	Client::setCommand(std::string command)
{
  this->_command = command;
}

std::string	Client::getCommand()
{
  return _command;
}

int	Client::get_port() const
{
  return _port;
}

void	Client::set_team_name(const std::string &team_name)
{
  Client::_team_name = team_name;
}

const std::string	&Client::get_team_name() const
{
  return _team_name;
}

const std::string	&Client::get_address() const
{
  return _address;
}

const sockaddr_in	&Client::get_sin() const
{
  return _sin;
}

int	Client::get_sock() const
{
  return _sock;
}
