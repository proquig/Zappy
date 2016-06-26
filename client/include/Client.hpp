//
// Client.hpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client/include
//
// Made by jacque_x
// Login   <jacque_x@epitech.net>
//
// Started on  Wed Jun 15 19:02:22 2016 jacque_x
// Last update Sun Jun 26 14:30:55 2016 jacque_x
//

#ifndef _CLIENT_HPP_
#define _CLIENT_HPP_

#include        <stdlib.h>
#include	    <ext/stdio_filebuf.h>
#include	    <fstream>
#include	    <iostream>
#include        <stdio.h>
#include        <memory.h>
#include        <netdb.h>
#include        <zconf.h>
#include        <vector>
#include        <ctime>
#include        <sstream>
#include        <iterator>
#include        <sys/types.h>
#include        <sys/socket.h>
#include        <netinet/in.h>
#include        <arpa/inet.h>
#include        <unistd.h>
#include        <map>
#include        <string>
#include	    "SocketBuf.hpp"

class Client
{
private:
    int                 _port;
    int                 _sock;
    std::string         _team_name;
    std::string         _address;
    std::string         _command;
    struct sockaddr_in  _sin;
    Socket              _socket1;

public:
    Client(int, std::string &, std::string &);
    ~Client();
    void        create_socket();
    void        init_struct();
    std::string getCommand();
    void        setCommand(std::string command);
    void        connect_to_server();
    bool        mygetline(std::string &);

    /* Getter */
    int                 get_port() const;
    const std::string   &get_team_name() const;
    const std::string   &get_address() const;
    const sockaddr_in   &get_sin() const;
    int                 get_sock() const;
    /* Setter */
    void                set_team_name(const std::string &_team_name);
};

void get_command(Client client);
std::vector<std::string> verif_params(char **av);
void error(const char *msg);
void print(std::string command, int i);
void verif2(std::vector<std::string> args);

#endif
