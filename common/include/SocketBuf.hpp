//
// Created by cloquet on 18/06/16.
//

#ifndef CLIENT_SOCKETBUF_HPP
#define CLIENT_SOCKETBUF_HPP

#include <streambuf>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>

class 		Socket
{
  int 		_fd_socket;
  std::string 	_command;
  FILE          *_f;
 public:
  Socket(){};

  ~Socket()
  { };

int  getFdSocket()
{
  return (this->_fd_socket);
}

  void	setFdSocket(int fd)
  {
    _fd_socket = fd;
  }

void  initFileFd()
{
    if (!(this->_f = fdopen(this->_fd_socket, "r")))
    {
      perror("fdopen");
      exit(-1);
    }
}

  std::string &read()
  {
    char *buf;
    size_t len;
    int a;

    buf = NULL;

    if ((a = getline(&buf, &len, this->_f)) <= 0)
    {
      if (a == -1)
        exit(EXIT_FAILURE);
      if (a == 0)
        {
          _command.clear();
          return (_command);
        }
    }
    buf[a] = 0;
    _command = buf;
    free(buf);
    return _command;
  };

  void my_write(std::string const &message)
  { 
    write(this->_fd_socket, message.c_str(), message.length());
  }
};


#endif //CLIENT_SOCKETBUF_HPP
